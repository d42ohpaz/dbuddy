const TerserPlugin = require('terser-webpack-plugin');
const path = require('path');
const webpack = require('webpack');

module.exports = {
    entry: {bundle: [path.resolve(__dirname, 'html/scripts/main.js')]},
    resolve: {
        extensions: ['.js'],
        symlinks: false,
    },
    module: {
        rules: [
            {
                test: /\.js$/,
                exclude: /(node_modules)/,
                use: [
                    {loader: 'babel-loader', options: {presets: ['@babel/preset-env']}}
                ],
            },
        ],
    },
    optimization: {
        minimize: true,
        minimizer: [
            new TerserPlugin({
                extractComments: false,
                terserOptions: {
                    compress: {ecma: 2018, drop_console: true},
                    format: {comments: false},
                },
            }),
        ],
        splitChunks: {
            cacheGroups: {
                default: false,
                vendors: false,
                vendor: {
                    name: 'vendor',
                    chunks: 'all',
                    test: /node_modules/,
                    priority: 20
                },
                common: {
                    name: 'common',
                    minChunks: 2,
                    chunks: 'all',
                    priority: 10,
                    reuseExistingChunk: true,
                    enforce: true
                },
            },
        },
    },
    output: {
        chunkFilename: '[name].js',
        publicPath: '/',
        path: path.resolve(__dirname, 'data/scripts'),
        filename: '[name].js',
    },
    plugins: [
        new webpack.ProvidePlugin({
            $: 'jquery'
        }),
    ],
}
