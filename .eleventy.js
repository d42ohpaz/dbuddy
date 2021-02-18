const EleventyPluginMinifyHtml = require('@dyve/eleventy-plugin-minifyhtml');

const PROD = process.env.NODE_ENV === 'production';

module.exports = (config) => {
    config.addPlugin(EleventyPluginMinifyHtml, {minify: PROD});

    return {
        dir: { input: 'html', output: 'data' },
        passthroughFileCopy: true,
        templateFormats: ["html", "css"],
    };
};
