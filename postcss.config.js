const path = require('path');

const autoprefixer = require('autoprefixer');
const cssnano = require('cssnano');
const PostcssImport = require('postcss-import');
const PostcssNested = require('postcss-nested');
const PostcssPurgecss = require('@fullhuman/postcss-purgecss');

const PROD = process.env.NODE_ENV === 'production';

const plugins = [
    PostcssImport({
        from: path.resolve(__dirname, 'html/css'),
        resolve: id => id.startsWith('~') ? id.substring(1, id.length) : id,
    }),
    PostcssPurgecss({
        content: [path.resolve(__dirname, 'data/**/*.html')],
    }),
    cssnano({ preset: 'default', discardComments: { "removeAll": true } }),
    PostcssNested,
    autoprefixer,
];

module.exports = {
    map: !PROD,
    plugins
};
