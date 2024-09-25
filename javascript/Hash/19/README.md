## 문제 (19.js)

문자열 해싱을 이용한 검색 함수 만들기

- 문자열 리스트 stringList와 쿼리 리스트 queryList가 있을 때 각 쿼리 리스트에 있는 문자열이 stringList의 문자열 리스트에 있는지 여부를 확인해야한다
- 문자열이 있으면 true, 없으면 false가 된다.
- 각 문자열에 대해서 문자열의 존재 여부를 리스트 형태로 반환하는 solution()함수를 작성하기

제약 조건

- 입력 문자열은 영어 소문자로만 이루어져 있다
- 문자열의 최대 길이는 10<sup>6</sup>입니다.
- 해시 충돌은 없습니다.
- 아래와 같은 문자열 해싱 방법을 활용해서 해싱 함수를 구현하세요
- 다음 식에서 p는 31, m은 1,000,000,007로 합니다.
  - hash(s) = (s[0] + s[1]*p + s[2]*p<sup>2</sup> ...... s[n-1]\*p<sup>n-1</sup>) mod m

권장 시간 복잡도: `O(N+K)`

## 풀이

1. 문자열 해싱 함수 구현
2. 문자열을 해싱 함수를 사용하여 해싱
3. 문자열을 해싱한 리스트에서 queryList에 있는 query를 hash하여 찾음
4. 찾으면 true 못찾으면 false

## Reference

- [MDN String.prototype.charCodeAt()](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/String/charCodeAt)
- [MDN Array.prototype.find()](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Array/find)
- [MDN Array.prototype.map()](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Array/map)
- [MDN Array.prototype.push()](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Array/push)
