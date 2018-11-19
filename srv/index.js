// import .env file, the variables are now in process.env object
require('dotenv').config()

// base requirements
var express     = require('express')
  , bodyParser  = require('body-parser')

// set up server port and body parsing
const app = express()
const port = process.env.PORT
app.use(bodyParser.json())

// reqire server routes
require('./routes')(app);

// start server
app.listen(port, () => console.log(`Game server listing on port ${port}!`))
