var ExtractTextPlugin = require("extract-text-webpack-plugin");
module.exports = {
  entry: {
    'main': ["./public/main.js"],
  },
  output: {
    path: "./public/build",
    filename: "superfile.js"
  },
  watch: true,
  devtool: "source-map",
  module: {
    loaders: [
      {
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
    new ExtractTextPlugin("style.css",  {allChunks: true})
  ]
};