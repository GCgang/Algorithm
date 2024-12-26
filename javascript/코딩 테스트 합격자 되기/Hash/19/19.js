function hash(str) {
  const p = 31;
  const m = 1_000_000_007;
  let hashValue = 0;
  for (let i = 0; i < str.length; ++i) {
    hashValue = (hashValue * p + str.charCodeAt(i)) % m;
  }
  return hashValue;
}

function solution(stringList, queryList) {
  const result = [];
  const hashList = stringList.map((str) => hash(str));

  for (const query of queryList) {
    if (hashList.find((str) => str === hash(query))) {
      result.push(true);
    } else {
      result.push(false);
    }
  }
  return result;
}

const strList = ['apple', 'banana', 'cherry'];
const qList = ['banana', 'kiwi', 'melon', 'apple'];
const result = solution(strList, qList);
console.log(result);
