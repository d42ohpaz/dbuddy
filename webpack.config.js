const path = require('path');

const CopyWebpackPlugin = require('copy-webpack-plugin');
const TerserWebpackPlugin = require('terser-webpack-plugin');
const webpack = require('webpack');

const PROD = process.env.NODE_ENV === 'production';

module.exports = {
    entry: {
        global: path.resolve(__dirname, 'html/scripts/main.js'),
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
            'window.$': PROD ? undefined : 'jquery',
        }),
    ],
}
