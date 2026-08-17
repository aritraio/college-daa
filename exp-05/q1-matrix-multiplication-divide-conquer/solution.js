const readline = require("readline");

const rl = readline.createInterface({ input: process.stdin });
let lines = [];
rl.on("line", (line) => lines.push(line.trim()));
rl.on("close", () => {
    let idx = 0;
    const n = parseInt(lines[idx++]);
    const A = [];
    const B = [];
    for (let i = 0; i < n; i++)
        A.push(lines[idx++].split(" ").map(Number));
    for (let i = 0; i < n; i++)
        B.push(lines[idx++].split(" ").map(Number));

    function subMatrix(M, r0, c0, size) {
        const S = Array.from({ length: size }, (_, i) =>
            M[r0 + i].slice(c0, c0 + size));
        return S;
    }

    function putQuad(S, M, r0, c0) {
        const size = S.length;
        for (let i = 0; i < size; i++)
            for (let j = 0; j < size; j++)
                M[r0 + i][c0 + j] = S[i][j];
    }

    function addMat(A, B) {
        const m = A.length;
        const C = Array.from({ length: m }, () => new Array(m));
        for (let i = 0; i < m; i++)
            for (let j = 0; j < m; j++)
                C[i][j] = A[i][j] + B[i][j];
        return C;
    }

    function matMul(A, B, size) {
        if (size === 1) return [[A[0][0] * B[0][0]]];
        const s = size >> 1;
        const A11 = subMatrix(A, 0, 0, s);
        const A12 = subMatrix(A, 0, s, s);
        const A21 = subMatrix(A, s, 0, s);
        const A22 = subMatrix(A, s, s, s);
        const B11 = subMatrix(B, 0, 0, s);
        const B12 = subMatrix(B, 0, s, s);
        const B21 = subMatrix(B, s, 0, s);
        const B22 = subMatrix(B, s, s, s);

        const M1 = matMul(A11, B11, s);
        const M2 = matMul(A12, B21, s);
        const M3 = matMul(A11, B12, s);
        const M4 = matMul(A12, B22, s);
        const M5 = matMul(A21, B11, s);
        const M6 = matMul(A22, B21, s);
        const M7 = matMul(A21, B12, s);
        const M8 = matMul(A22, B22, s);

        const C11 = addMat(M1, M2);
        const C12 = addMat(M3, M4);
        const C21 = addMat(M5, M6);
        const C22 = addMat(M7, M8);

        const C = Array.from({ length: size }, () => new Array(size));
        putQuad(C11, C, 0, 0);
        putQuad(C12, C, 0, s);
        putQuad(C21, C, s, 0);
        putQuad(C22, C, s, s);
        return C;
    }

    const C = matMul(A, B, n);
    for (const row of C) console.log(row.join(" "));
});
