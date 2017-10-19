import configurate from "./config/express"

const express = require('express'),
  config = require('./config/config');
//mongoose = require('mongoose');

//mongoose.connect(config.db);
//const db = mongoose.connection;
//db.on('error', function () {
//  throw new Error('unable to connect to database at ' + config.db);
//});

const app = express();
configurate(app, config);

app.listen(config.port, function () {
  console.log('Express server listening on port ' + config.port);
});
