var ExtractTextPlugin = require("extract-text-webpack-plugin");
module.exports = {
  entry: {
    'main': ["./app.js"],
  },
  output: {
    path: __dirname + "/public/build",
    filename: "superfile.js",
    publicPath: '/'

  },
  node: {
    fs: "empty",
    net: 'empty',
    dns: 'empty'
  },
  watch: true,
  module: {
    loaders: [{
        test: /\.js$/,
        exclude: /node_modules/,
        loader: 'babel-loader'
      },
      {
        test: /\.css$/,
        loader: ExtractTextPlugin.extract("style", "css")
      },
      {
        test: /\.scss$/,
        loader: ExtractTextPlugin.extract("style", "css!sass")
      }
    ]
  },
  plugins: [
    new ExtractTextPlugin("style.css", {
      allChunks: true
    })
  ]
};
