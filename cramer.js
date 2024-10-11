"use strict";

const A = [
  [4, -2, 1, 3, 0],
  [0, 5, -1, 2, 4],
  [3, 2, 6, -4, 1],
  [-1, 0, 4, 7, 5],
  [2, -3, 0, 1, 8],
];

const B = [10, 15, 25, 30, 5];

const Calcramer = (A, B) => {
  const n = A.length;
  let x = [];

  // calculate determinant
  const Anydet = (A) => {
    let det = 0;
    let n = A.length;

    if (n === 1) {
      return A[0][0];
    } else if (n === 2) {
      return A[0][0] * A[1][1] - A[0][1] * A[1][0];
    } else {
      let mainrow = 0;
      for (let i = 0; i < n; i++) {
        det += A[mainrow][i] * cofactor(A, mainrow, i);
      }
      return det;
    }
  };

  const cofactor = (A, i, j) => {
    const B = minor(A, i, j);
    return Math.pow(-1, i + j) * Anydet(B);
  };

  const minor = (A, i, j) => {
    const n = A.length;
    const B = [];
    for (let k = 0; k < n; k++) {
      if (k !== i) {
        const row = [];
        for (let l = 0; l < n; l++) {
          if (l !== j) {
            row.push(A[k][l]);
          }
        }
        B.push(row);
      }
    }
    return B;
  };
  // calculate determinant

  let detA = Anydet(A);
  if (detA === 0) {
    console.log("Matrix is singular, cannot solve using Cramer's rule.");
    return;
  }
  for (let i = 0; i < n; i++) {
    let temp = [];
    for (let j = 0; j < n; j++) {
      let temp2 = [];
      for (let k = 0; k < n; k++) {
        if (k === i) {
          temp2[k] = B[j];
        } else {
          temp2[k] = A[j][k];
        }
      }
      temp.push(temp2);
    }
    x[i] = Anydet(temp) / detA;
  }
  return x;
};

console.log(Calcramer(A, B));
