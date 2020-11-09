const path = require('path');
const common = require('./webpack.common.js');
const wm = require('webpack-merge');
const cwp = require('clean-webpack-plugin');

module.exports = wm.merge(common, {
  mode: 'production',
  output: {
    filename: 'index.[contentHash].js',
    path: path.join(__dirname, 'build')
  },
  plugins: [
    new cwp.CleanWebpackPlugin()
  ]
});