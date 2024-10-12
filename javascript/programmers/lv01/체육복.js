// https://school.programmers.co.kr/learn/courses/30/lessons/42862
function solution(n, lost, reserve) {
  let realLost = lost.filter((l) => !reserve.includes(l));
  let realReserve = reserve.filter((r) => !lost.includes(r));

  realLost.sort((a, b) => a - b);
  realReserve.sort((a, b) => a - b);

  for (let i = 0; i < realReserve.length; ++i) {
    if (realLost.includes(realReserve[i] - 1)) {
      realLost = realLost.filter((l) => l !== realReserve[i] - 1);
    } else if (realLost.includes(realReserve[i] + 1)) {
      realLost = realLost.filter((l) => l !== realReserve[i] + 1);
    }
  }
  return n - realLost.length;
}
