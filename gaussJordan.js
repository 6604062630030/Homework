"use strict";

const A = [
  [4, -2, 1, 3, 0],
  [0, 5, -1, 2, 4],
  [3, 2, 6, -4, 1],
  [-1, 0, 4, 7, 5],
  [2, -3, 0, 1, 8],
];

const B = [10, 15, 25, 30, 5];

const CalGaussJordan = (A, B) => {
  const n = A.length;

  // B into A
  for (let i = 0; i < n; i++) {
    A[i].push(B[i]);
  }

  for (let i = 0; i < n; i++) {
    if (A[i][i] === 0) {
      let swapRow = i + 1;
      while (swapRow < n && A[swapRow][i] === 0) {
        swapRow++;
      }
      if (swapRow === n) {
        console.log("Error");
        return;
      }
      [A[i], A[swapRow]] = [A[swapRow], A[i]];
    }

    let makeOne = A[i][i];
    for (let j = 0; j < n + 1; j++) {
      A[i][j] /= makeOne;
    }

    for (let j = 0; j < n; j++) {
      if (j !== i) {
        let factor = A[j][i];
        for (let k = 0; k < n + 1; k++) {
          A[j][k] -= factor * A[i][k];
        }
      }
    }
  }

  let x = [];
  for (let i = 0; i < n; i++) {
    x.push(A[i][n]);
  }

  return x;
};

console.log(CalGaussJordan(A, B));
