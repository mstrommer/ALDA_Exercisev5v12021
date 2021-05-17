//
//  sort.cpp
//  ALDA_Exercise5v12021_Solution
//
//  Created by Michael Strommer on 17.05.21.
//

#include "sort.hpp"


void swap(element *xp, element *yp)
{
    element temp = *xp;
    *xp = *yp;
    *yp = temp;
}


void selection_sort_fp(element* stations, int n, int (*comp)(element*, element*)){
    int i, j, min_idx;
    
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (comp(&stations[j], &stations[min_idx]) < 0)
                min_idx = j;
        
        // Swap the found minimum element with the first element
        swap(&stations[min_idx], &stations[i]);
    }
}

void selection_sort(element* stations, int n)
{
    int i, j, min_idx;
    
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (strcmp(stations[j].station_name, stations[min_idx].station_name) < 0)
                min_idx = j;
        
        // Swap the found minimum element with the first element
        swap(&stations[min_idx], &stations[i]);
    }
}

/*
 Comment
 */
void merge_sort(element* stations, element* tmpStations, int left, int right)
{
// tmpStations corresponds to the array B in the lecture slides
// function to sort the subsection a[i .. j] of the array a[]

    if (right <= left) {
        return;     // the subsection is empty or a single element
    }
    int mid = (left + right) / 2;
    // left sub-array is a[i .. mid]
    // right sub-array is a[mid + 1 .. j]
    merge_sort(stations, tmpStations, left, mid);       // sort the left sub-array recursively
    merge_sort(stations, tmpStations, mid + 1, right);  // sort the right sub-array recursively
    int pointer_left = left;       // pointer_left points to the beginning of the left sub-array
    int pointer_right = mid + 1;   // pointer_right points to the beginning of the right sub-array
    int k;      // k is the loop counter
    // we loop from i to j to fill each element of the final merged array
    for (k = left; k <= right; k++)
    {
        if (pointer_left == mid + 1)
        {      // left pointer has reached the limit
            tmpStations[k] = stations[pointer_right];
            pointer_right++;
        }
        else if (pointer_right == right + 1)
        {        // right pointer has reached the limit
            tmpStations[k] = stations[pointer_left];
            pointer_left++;
        }
        else if (strcmp(stations[pointer_left].station_name, stations[pointer_right].station_name) > 0)
        {        // pointer left points to smaller element
            tmpStations[k] = stations[pointer_left];
            pointer_left++;
        }
        else
        {        // pointer right points to smaller element
            tmpStations[k] = stations[pointer_right];
            pointer_right++;
        }
    }
    for (k = left; k <= right; k++) {      // copy the elements from aux[] to a[]
        stations[k] = tmpStations[k];
    }
}
