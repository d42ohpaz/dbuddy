const compressing = require('compressing');
const yargs = require('yargs');
const fs = require('fs');
const path = require('path');
const glob = require('glob');

const argv = yargs
    .command('$0 <path...>', 'Compress files using gzip compression', yargs => {
        yargs.positional('path', {
            describe: 'The file(s) or directory(ies) of files you want to compress',
            type: 'array',
        });
    })
    .option('output', {
        alias: 'o',
        type: 'string',
        description: `The output directory of the compressed file(s); default is ${__dirname}`,
    }).argv;

if (typeof argv.output === 'undefined' || argv.output === null || argv.output.length === 0) {
    argv.output = path.resolve(__dirname);
}

try {
    if (!fs.lstatSync(argv.output).isDirectory()) {
        console.error('Error: %s is not a directory', argv.output);
        return 1;
    }
} catch (e) {
    console.error(`Error: %s`, e.message);
    return 1;
}

// O(n^2) complexity
const resolveGlob = (paths) => {
    for (const p of paths) {
        if (fs.lstatSync(p).isDirectory()) {
            const root = path.dirname(path.isAbsolute(p) ? p : path.resolve(__dirname, p));
            const matches = glob.sync(path.resolve(p, '**'));

            for (const match of matches) {
                // At this point, glob() has recursively gotten us all the
                // files, so we can safely ignore any directories.
                if (fs.lstatSync(match).isFile()) {
                    paths.push(path.relative(root, match));
                }
            }
        }
    }
    return paths;
};

// First pass: expand any directories using glob()
let inputPaths = resolveGlob(argv.path);

// Final pass: remove any directories from the list
inputPaths = inputPaths.filter(p => fs.lstatSync(p).isFile());

console.log(`Compressing ${inputPaths.length} files...`);
inputPaths.forEach((file) => {
    const dest = path.resolve(argv.output, `${file}.gz`);
    fs.mkdirSync(path.dirname(dest), {recursive: true});

    compressing.gzip.compressFile(file, dest)
        .then(() => {
            fs.rmSync(file);
        })
});
