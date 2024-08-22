## 문제 (16.js)

[기능 개발](https://school.programmers.co.kr/learn/courses/30/lessons/42586)

권장 시간 복잡도: `O(N)`

## 풀이

1. 각 작업의 배포 가능일을 구한다.
2. 작업을 진행하며 배포 가능일이 첫 번째 작업일보다 빠른 작업들은 함께 배포한다.
3. 첫 번째 작업의 배포 가능일보다 늦은 작업이 나오면, 해당 작업의 배포일을 기준으로 뒤의 작업들을 배포한다.
4. 모든 작업이 완료될 때까지 반복한다.

## Reference

- [MDN Math.ceil()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Math/ceil)
- [MDN Array.prototype.map()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/map)
- [MDN Array.prototype.push()](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/push)
