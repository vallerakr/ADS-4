// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i+1; j < len; j++) {
      if ((arr[i] + arr[j] == value) && (arr[i] >=0 && arr[j] >= 0)) {
        count++;
      }
    }
  }
   return count == 0 ? 0 : count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int right = len - 1;
  while (arr[right] > value) {
    right--;
  }
  for (int i =0; i < right; i++) {
    for (int j = right; j > i; j--) {
      if ((arr[i] + arr[j] == value) && (arr[i] >=0 && arr[j] >= 0)) {
        count++;
      } else if (arr[i] + arr[j] < value) {
        break;
      }
    }
  }
   return count == 0 ? 0 : count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    int left = i;
    int right = len;
    while (left < right - 1) {
      int center = (right + left) / 2;
      if (arr[i] + arr[center] == value) {
        count++;
        int temp = center + 1;
        while ((arr[i] + arr[temp] == value) && (temp < right)) {
          count++;
          temp++;
        }
        temp = center - 1;
        while ((arr[i] + arr[temp] == value) && (temp > left)) {
          count++;
          temp--;
        }
        break;
      } else if (arr[i] + arr[center] > value) {
        right = center;
      } else {
        left = center;
      }
    }
  }
   return count == 0 ? 0 : count;
}
