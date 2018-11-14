/* firebaseController.js
 *
 * handles all connection to firebase
 */


// requirements
var firebase = require('firebase')

// configure and start connection
var config =
  { apiKey            : process.env.FIREBASE_API_KEY
  , authDomain        : process.env.FIREBASE_AUTH_DOMAIN
  , databaseURL       : process.env.FIREBASE_DATABASE_URL
  , projectId         : process.env.FIREBASE_PROJECT_ID
  , storageBucket     : process.env.FIREBASE_STORAGE_BUCKET
  , messagingSenderId : process.env.FIREBASE_MESSAGE_SENDER_ID
  }
firebase.initializeApp(config)
var database = firebase.database()

// write data out to firebase
async function writeData(username, score) {
  await database.ref(process.env.FIREBASE_SUB_DATABASE_NAME + '/' + username).set({score})
  return
}

// get top n scores from firebase
async function getTopScores(numberOfScores) {

  // build query
  var dataObj = await database
          .ref(process.env.FIREBASE_SUB_DATABASE_NAME)
          .orderByChild('score')
          .limitToLast(numberOfScores)
          .once('value')

  // shove data into format to send to client-
  // needs to be reversed and parsed
  var finalDataObj = []
  dataObj.forEach(function(record) {
    finalDataObj.unshift(record.val())
    finalDataObj[0].username = record.key
  })

  return finalDataObj
}

// export the two functions for use in other files
module.exports =
  { writeData
  , getTopScores
  }
