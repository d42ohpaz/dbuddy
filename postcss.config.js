const path = require('path');

const atImport = require('postcss-import');
const autoprefixer = require('autoprefixer');
const cssnano = require('cssnano');
const nested = require('postcss-nested');
const purgeCSS = require('@fullhuman/postcss-purgecss');

const plugins = [
    atImport({
        resolve: (id) => {
            if (id.startsWith('~')) {
                return id.substring(1, id.length);
            }

            return id;
        }
    }),
    cssnano({ preset: 'default', discardComments: { "removeAll": true } }),
    purgeCSS({
        content: [path.resolve(__dirname, 'data/**/*.html')],
    }),
    nested,
    autoprefixer,
];

module.exports = {
    map: false,
    plugins
};
