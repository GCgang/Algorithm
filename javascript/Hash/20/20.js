function solution(participant, completion) {
  const hashTable = {};

  for (const p of participant) {
    if (hashTable[p]) {
      hashTable[p]++;
    } else {
      hashTable[p] = 1;
    }
  }
  for (const c of completion) {
    hashTable[c]--;
  }

  for (const key in hashTable) {
    if (hashTable[key] > 0) {
      return key;
    }
  }
  return;
}
