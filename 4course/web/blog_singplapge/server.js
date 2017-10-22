const express = require('express');
const parser = require('body-parser');
var async = require('async');

const app = express();
//import Server from "./public/server/server"
const handler = require("./public/server/server")

app.use('/', express.static('public', {
  maxAge: 2
}));

app.use(parser.json());
app.use('/libs', express.static('node_modules'));
app.use('/css', express.static(__dirname + '/node_modules/bootstrap/dist/css'));
app.use('/soc', express.static(__dirname + '/node_modules/bootstrap-social'));
app.use("/simplemde", express.static(__dirname + '/node_modules/simplemde/dist'))



app.listen(process.env.PORT || 3000, () => {
  console.log(`App started on port ${process.env.PORT || 3000}`);
});

function pseudoUrlHandler(req, res) {
  res.sendFile('public/index.html', {
    root: __dirname
  });
}

async function pseudoServerUrlHanderl(req, res) {
  //let server = new Server(req);
  console.log("hey")
  const resp = await handler.response(req);
  res.setHeader('Content-Type', 'application/json');
  res.send(JSON.stringify({
    a: resp
  }));
}
app.post('/api/session', pseudoServerUrlHanderl)
app.get('/login', pseudoUrlHandler);
app.get('/create', pseudoUrlHandler);
app.get('/post/:id', pseudoUrlHandler);