"use strict";

const A = [
  [4, -2, 1, 3, 0],
  [0, 5, -1, 2, 4],
  [3, 2, 6, -4, 1],
  [-1, 0, 4, 7, 5],
  [2, -3, 0, 1, 8],
];

const B = [10, 15, 25, 30, 5];

const Calgauss = (A, B) => {
  const n = A.length;

  // Forward
  for (let i = 0; i < n; i++) {
    if (A[i][i] === 0) {
      let swapRow = i + 1;
      while (swapRow < n && A[swapRow][i] === 0) {
        swapRow++;
      }
      if (swapRow === n) {
        console.log("Error: no solution");
        return;
      }
      // Swap rows
      [A[i], A[swapRow]] = [A[swapRow], A[i]];
      [B[i], B[swapRow]] = [B[swapRow], B[i]];
    }

    for (let j = i + 1; j < n; j++) {
      let Divider = A[j][i] / A[i][i];
      for (let k = i; k < n; k++) {
        A[j][k] -= Divider * A[i][k];
      }
      B[j] -= Divider * B[i];
    }
  }

  let x = new Array(n);
  for (let i = n - 1; i >= 0; i--) {
    let sum = 0;
    for (let j = i + 1; j < n; j++) {
      sum += A[i][j] * x[j];
    }
    x[i] = (B[i] - sum) / A[i][i];
  }

  return x;
};

console.log(Calgauss(A, B));
