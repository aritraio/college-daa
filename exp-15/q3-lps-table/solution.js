const readline = require('readline');

const rl = readline.createInterface({ input: process.stdin, output: process.stdout });

rl.on('line', (pattern) => {
    const m = pattern.length;
    const lps = new Array(m).fill(0);
    let len = 0, i = 1;
    while (i < m) {
        if (pattern[i] === pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else if (len !== 0) {
            len = lps[len - 1];
        } else {
            lps[i] = 0;
            i++;
        }
    }
    let out = "LPS:";
    for (i = 0; i < m; i++) out += " " + lps[i];
    console.log(out);
    rl.close();
});
