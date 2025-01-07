## 문제 (30.js)

- [미로 탈출](https://school.programmers.co.kr/learn/courses/30/lessons/159993)
  권장 시간 복잡도: `O(N^2)`

## 풀이

1. 시작위치, 레버위치, 출구 위치를 구한다
2. bfs 함수를 만들어서 최단경로를 구한다.
3. 시작 -> 레버 최단거리를 구한다
4. 레버 -> 탈출 최단거리를 구한다.
5. 미로를 탈출하는 데 필요한 최소 시간을 반환한다.

## Reference

- [Array.from()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/from)
- [Array.prototype.shift()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/shift)
