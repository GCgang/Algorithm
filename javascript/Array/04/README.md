## 문제 (04.js)

[모의고사](https://school.programmers.co.kr/learn/courses/30/lessons/42840)

권장 시간 복잡도: `O(N)`

## 풀이

1. 수포자의 찍기 패턴 배열을 저장
2. 입력으로 주어진 정답 배열을 for...of 으로 순회하며 각 수포자의 찍기 패턴과 일치하는 정답 개수를 카운팅
3. 가장 높은 점수를 저장
4. 가장 높은 점수를 받은 수포자들의 번호를 결과 배열에 저장하여 반환

## Reference

- [MDN for...of](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for...of)
- [MDN Array.prototype.entries()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/entries)
- [MDN Math.max](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math/max)
