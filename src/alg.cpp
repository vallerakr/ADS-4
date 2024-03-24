// Copyright 2021 NNTU-CS
#include <iostream>
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            count++;
            left++;
            right--;
        } else if (sum < value) {
            left++;
        } else {
            right--;
        }
    }

    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; i++) {
        int left = i + 1;
        int right = len - 1;
        int complement = value - arr[i];

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == complement) {
                count++;
                break;
            } else if (arr[mid] < complement) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return count;
}
