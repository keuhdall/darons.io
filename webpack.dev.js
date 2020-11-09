const path = require('path');
const common = require('./webpack.common.js');
const wm = require('webpack-merge');

module.exports = wm.merge(common, {
  mode: 'development',
  output: {
    filename: 'index.js',
    path: path.join(__dirname, 'dist')
  }
});