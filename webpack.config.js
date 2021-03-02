const path = require('path');

const CopyWebpackPlugin = require('copy-webpack-plugin');
const TerserWebpackPlugin = require('terser-webpack-plugin');
const webpack = require('webpack');

const PROD = process.env.NODE_ENV === 'production';

module.exports = {
    entry: {
        global: path.resolve(__dirname, 'html/scripts/main.js'),
        wifi: path.resolve(__dirname, 'html/scripts/wifi.js'),
        calendars: path.resolve(__dirname, 'html/scripts/calendars.js'),
    },
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
        minimize: PROD,
        minimizer: [
            new TerserWebpackPlugin({
                extractComments: false,
                terserOptions: {
                    compress: {ecma: 2018, drop_console: PROD},
                    format: {comments: false},
                },
            }),
        ],
    },
    output: {
        chunkFilename: 'scripts/[name].js',
        publicPath: '/',
        path: path.resolve(__dirname, 'data'),
        filename: 'scripts/[name].js',
    },
    plugins: [
        new CopyWebpackPlugin({
            patterns: [
                {from: path.resolve(__dirname, 'html/fonts/**/*'), to: 'fonts', context: path.resolve(__dirname, 'html/fonts')},
            ],
        }),
        new webpack.ProvidePlugin({
            $: 'jquery',
            jQuery: 'jquery',
            'window.$': PROD ? undefined : 'jquery',
        }),
    ],
}
