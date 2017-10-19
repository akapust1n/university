const path = require('path'),
  rootPath = path.normalize(__dirname + '/..'),
  env = process.env.NODE_ENV || 'development';

const config = {

  production: {
    root: rootPath,
    app: {
      name: 'blog'
    },
    port: process.env.PORT || 8080,
    db: 'mongodb://localhost/web'
  }
};
