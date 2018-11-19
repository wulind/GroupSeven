/* routes.js
 *
 * descrives all http request routes
 *
 * POST /score
 * adds a score to the firebase database
 *
 * GET /topScores
 * get the top 5 scores from the database
 */

// import custom firebase interface file
var firebaseController  = require('./firebaseController.js')

// begin actual module
module.exports = function(app){

  // add a single score to the database
  app.post('/score', async function(req, res) {

    // if the proper fields were not sent, return a 400 error
    if(!req.body.hasOwnProperty('username') || !req.body.hasOwnProperty('score')) {
      res.send('must include username and score with request', 400)
      return
    }

    await firebaseController.writeData(req.body.username, req.body.score)

    res.send('success');
  });

  // get top 5 scores from database
  app.get('/topScores', async function(req, res) {

    var topScores = await firebaseController.getTopScores(5)

    res.send(topScores)
  })
}
