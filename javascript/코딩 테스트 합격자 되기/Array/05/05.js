function solution(arr1, arr2) {
  const r1 = arr1.length;
  const c1 = arr1[0].length;

  const r2 = arr2.length;
  const c2 = arr2[0].length;

  let answer = [...new Array(r1)].map(() => new Array(c2).fill(0));

  // 첫 번째 행렬 arr1의 각 행과 두 번째 행렬 arr2의 각 열에 대해
  for (let i = 0; i < r1; ++i) {
    for (let j = 0; j < c2; ++j) {
      // 두 행렬의 데이터를 곱해 결과 배열에 더하기
      for (let k = 0; k < c1; ++k) {
        answer[i][j] += arr1[i][k] * arr2[k][j];
      }
    }
  }
  return answer;
}
