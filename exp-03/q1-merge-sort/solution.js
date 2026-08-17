const readline = require("readline");

function merge(arr, left, mid, right) {
    const n1 = mid - left + 1;
    const n2 = right - mid;
    const L = new Array(n1);
    const R = new Array(n2);

    for (let i = 0; i < n1; i++) L[i] = arr[left + i];
    for (let j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    let i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

function mergeSort(arr, left, right) {
    if (left < right) {
        const mid = left + Math.floor((right - left) / 2);
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

const rl = readline.createInterface({ input: process.stdin });
const lines = [];

rl.on("line", (line) => lines.push(line));

rl.on("close", () => {
    const nums = lines.join(" ").trim().split(/\s+/).map(Number);
    const n = nums[0];
    const arr = nums.slice(1, 1 + n);
    mergeSort(arr, 0, n - 1);
    console.log(arr.join(" "));
});