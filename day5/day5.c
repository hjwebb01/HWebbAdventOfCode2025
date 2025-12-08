#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    long long start;
    long long end;
} Range;

static Range* merge_overlapping_ranges(Range* ranges, int range_count, int* merged_count) {
    Range* merged_ranges = malloc(range_count * sizeof(Range));
    if (!merged_ranges) {
        return NULL;
    }

    int merged_idx = 0;
    merged_ranges[merged_idx] = ranges[0];

    for (int i = 1; i < range_count; i++) {
        Range* last = &merged_ranges[merged_idx];
        if (ranges[i].start <= last->end + 1) {
            if (ranges[i].end > last->end) {
                last->end = ranges[i].end;
            }
        } else {
            merged_idx++;
            merged_ranges[merged_idx] = ranges[i];
        }
    }

    *merged_count = merged_idx + 1;
    return merged_ranges;
}

int compare_ranges(const void* a, const void* b) {
    Range* r1 = (Range*)a;
    Range* r2 = (Range*)b;
    if (r1->start < r2->start) return -1;
    if (r1->start > r2->start) return 1;
    return 0;
}

int day5_part1(char** id_ranges, int id_ranges_size, char** ids, int ids_size) {
    if (id_ranges_size == 0) return 0;

    Range* ranges = malloc(id_ranges_size * sizeof(Range));
    if (!ranges) return -1;

    for (int i = 0; i < id_ranges_size; i++) {
        sscanf(id_ranges[i], "%lld-%lld", &ranges[i].start, &ranges[i].end);
    }

    qsort(ranges, id_ranges_size, sizeof(Range), compare_ranges);

    int merged_count = 0;
    Range* merged_ranges = merge_overlapping_ranges(ranges, id_ranges_size, &merged_count);
    if (!merged_ranges) {
        free(ranges);
        return -1;
    }

    int valid_id_count = 0;
    for (int i = 0; i < ids_size; i++) {
        long long id;
        sscanf(ids[i], "%lld", &id);
        
        for (int j = 0; j < merged_count; j++) {
            if (id >= merged_ranges[j].start && id <= merged_ranges[j].end) {
                valid_id_count++;
                break; 
            }
        }
    }

    free(ranges);
    free(merged_ranges);

    return valid_id_count;
}

long long day5_part2(char** id_ranges, int id_ranges_size) {
    if (id_ranges_size == 0) return 0;

    Range* ranges = malloc(id_ranges_size * sizeof(Range));
    if (!ranges) return -1;

    for (int i = 0; i < id_ranges_size; i++) {
        sscanf(id_ranges[i], "%lld-%lld", &ranges[i].start, &ranges[i].end);
    }

    qsort(ranges, id_ranges_size, sizeof(Range), compare_ranges);

    int merged_count = 0;
    Range* merged_ranges = merge_overlapping_ranges(ranges, id_ranges_size, &merged_count);
    if (!merged_ranges) {
        free(ranges);
        return -1;
    }

    long long valid_id_count = 0;
    for (int i = 0; i < merged_count; i++) {
        valid_id_count += (merged_ranges[i].end - merged_ranges[i].start + 1);
    }
    
    free(ranges);
    free(merged_ranges);

    return valid_id_count;
}

int main() {
    FILE* file;
    fopen_s(&file, "input.txt", "r");
    if (file == NULL) {
        return 1;
    }

    char** id_ranges = NULL;
    int id_ranges_size = 0;
    char** ids = NULL;
    int ids_size = 0;
    char line[256];
    int reading_id_ranges = 1;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;

        if (strlen(line) == 0) {
            reading_id_ranges = 0;
            continue;
        }

        if (reading_id_ranges) {
            char** temp = realloc(id_ranges, (id_ranges_size + 1) * sizeof(char*));
            if (temp == NULL) {
                printf("Memory allocation failed\n");
                fclose(file);
                return 1;
            }
            id_ranges = temp;

            id_ranges[id_ranges_size] = malloc(strlen(line) + 1);
            if (id_ranges[id_ranges_size] == NULL) {
                printf("Memory allocation failed\n");
                fclose(file);
                return 1;
            }
            strcpy_s(id_ranges[id_ranges_size], strlen(line) + 1, line);
            id_ranges_size++;
        } else {
            char** temp = realloc(ids, (ids_size + 1) * sizeof(char*));
            if (temp == NULL) {
                printf("Memory allocation failed\n");
                fclose(file);
                return 1;
            }
            ids = temp;

            ids[ids_size] = malloc(strlen(line) + 1);
            if (ids[ids_size] == NULL) {
                printf("Memory allocation failed\n");
                fclose(file);
                return 1;
            }
            strcpy_s(ids[ids_size], strlen(line) + 1, line);
            ids_size++;
        }
    }

    fclose(file);

    int result = day5_part1(id_ranges, id_ranges_size, ids, ids_size);
    printf("Result: %d\n", result);
    long long result2 = day5_part2(id_ranges, id_ranges_size);
    printf("Result2: %lld\n", result2);

    for (int i = 0; i < id_ranges_size; i++) {
        free(id_ranges[i]);
    }
    free(id_ranges);

    for (int i = 0; i < ids_size; i++) {
        free(ids[i]);
    }
    free(ids);

    return 0;
}