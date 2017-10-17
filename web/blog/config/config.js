var path = require('path'),
  rootPath = path.normalize(__dirname + '/..'),
  env = process.env.NODE_ENV || 'development';

var config = {
  development: {
    root: rootPath,
    app: {
      name: 'blog'
    },
    port: process.env.PORT || 8080,
    db: 'mongodb://localhost/web'
  },

  test: {
    root: rootPath,
    app: {
      name: 'blog'
    },
    port: process.env.PORT || 8080,
    db: 'mongodb://localhost/web'
  },

  production: {
    root: rootPath,
    app: {
      name: 'blog'
    },
    port: process.env.PORT || 8080,
    db: 'mongodb://localhost/web'
  }
};

module.exports = config[env];
