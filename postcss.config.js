const path = require('path');

const autoprefixer = require('autoprefixer');
const cssnano = require('cssnano');
const PostcssPresetEnv = require('postcss-preset-env');
const PostcssImport = require('postcss-import');
const PostcssNested = require('postcss-nested');
let PostcssPurgecss = require('@fullhuman/postcss-purgecss');

const PROD = process.env.NODE_ENV === 'production';

if (!PROD) {
    // Disable PurgeCSS when not in production.
    PostcssPurgecss = () => {};
}

const plugins = [
    PostcssPresetEnv({ stage: 0, browsers: 'last 2 versions' }),
    PostcssImport({
        from: path.resolve(__dirname, 'html/css'),
        resolve: id => id.startsWith('~') ? id.substring(1, id.length) : id,
    }),
    PostcssPurgecss({
        content: [
            path.resolve(__dirname, 'data/**/*.html'),
            path.resolve(__dirname, 'data/**/*.js'),
        ],
    }),
    cssnano({ preset: 'default', discardComments: { "removeAll": true } }),
    PostcssNested,
    autoprefixer,
];

module.exports = {
    map: !PROD,
    plugins
};
