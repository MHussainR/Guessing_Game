#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>


struct info {
	char name1[20];
	int notp;
	int total;
	int level1;
	int level2;
	int level3;
};



int random (int lower, int upper, int count){
	int i;
	for (i = 0; i < count; i++){
		int num = (rand() % (upper - lower + 1)) + lower;
		return num;
	}
}



char in_list (int lst[3], int ran){
	int i;
	for (i = 0; i < 3; i++){
		if (lst[i] == ran){
			return '1';
		}
	}
	
	return '0';
}



char check_prime(int x) {
	int i;
	for (i = 2; i < x; i++){
		if (x%i == 0){
			return '0';
		} 
		
	return '1';
	}
}



int check (int x){
	
	int ran;
	
	if (check_prime(x) == '0'){
		return x;
	} else {
		ran = random(1, 100, 1);
		return (check(ran));
	}
}



int check2 (int lst[3], int ran, int len){
	
	int ran1;
	
	if (in_list(lst, ran) == '0'){
		return ran;
	} else {
		ran1 = random(0, len, 1);
		return (check2(lst, ran1,len));
	}
}



int ran_num1 (int len, int lst[3]) {
	
	int num;
	
	num = random(0, len, 1);
	num = check2(lst, num, len);
	
	return num;
	
}


void print_lst (int lst[256], int ct){
	int i;
	
	for (i = 0; i < ct; i++){
		printf("%d ", lst[i]);
	}
	
	printf("\n");
}


int in_lst_2 (char lst [150][20], char x[20]){
    
    int i;
    int j;
    int k;
    
    for (i = 0; i < 10; i++){
        k = 0;
        
        for (j = 0; j < 20; j++){
        	
            if (lst[i][j] == x[j]){
                k++;   
            }   
        }
        if (k == 20){
            return i;   
        }
    }
    return 10000;   
}



void nooftimes (){
	
	int t[100];
	int n;
	int i;
	char *token;
	char help[256];
	char line[20];
	int a = 0;
	int b = 0;
	int c = 0;
	int k = 0;
	int temp;
	char lst[50][20];
	int notp[50];
	
	FILE * Name = fopen("name.txt", "r");
	FILE * total_scor = fopen("total.txt", "r");
	
	fscanf(total_scor, "%s", help);
	
	token = strtok(help, ",");
	
	i = 0;
	while (token != NULL) {
		
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	
	n = i;
	
	for (i = 0; i < n; i++){
		
		notp[i] = 1;	
	}
	
	while (!feof(Name)){
		
		if (a == n) {
			break;
		}
		
		fgets(line, 20, Name);
		
		temp = in_lst_2(lst, line);
		
		if (temp == 10000){
		
			for (b = 0; b < 20; b++){
				
				lst[c][b] = line[b];
			}
			
			c++;
		} else {
			
			k = notp[temp];
			k += 1;
			notp[temp] = k;
		}
		a++;
	}
	
	for (i = 0; i < c; i++){
		printf("%splayed %d time/s\n", lst[i], notp[i]);
	}	
}



void total_high_score (){
	
	int t[100];
	int n;
	int i;
	char *token;
	char help[256];
	char line[150];
	int a = 0;
	int b = 0;
	int j = 0;
	int k = 0;
	int temp;
	char tempc[20];
	char lst[50][20];
	
	FILE * Name = fopen("name.txt", "r");
	FILE * total_scor = fopen("total.txt", "r");
	
	fscanf(total_scor, "%s", help);
	
	token = strtok(help, ",");
	
	i = 0;
	while (token != NULL) {
		
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	
	n = i;
	
	while (!feof(Name)){
		
		if (a == n) {
			break;
		}
		
		fgets(line, 150, Name);
		
		for (b = 0; b < 20; b++){
			
			lst[a][b] = line[b];
	
		}
		
		a++;
	
	}
	
	fclose(total_scor);
	
	for (j = 0; j < n; j++){
		
		for (k = 0; k < n-j-1; k++){
			
			if (t[k] < t[k+1]){
				
				temp = t[k];
				t[k] = t[k+1];
				t[k+1] = temp;
				
				
				for (i = 0; i < 20; i++){
					tempc[i] = lst[k][i];
					lst[k][i] = lst[k+1][i];
					lst[k+1][i] = tempc[i];
				}
					
			}
			
		}
		
	}
	
	for (i = 0; i < n; i++){
		
		printf("%s: %d\n", lst[i], t[i]);
		
	}
}



void total_score () {
	int t[100];
	int n;
	int i;
	
	char *token;
	char help[256];
	char line[150];
	int a = 0;
	
	FILE * Name = fopen("name.txt", "r");
	FILE * total_scor = fopen("total.txt", "r");
	
	fscanf(total_scor, "%s", help);
	
	token = strtok(help, ",");
	
	i = 0;
	while (token != NULL) {
		
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	
	n = i;
	
	while (!feof(Name)){
		
		if (a == n) {
			break;
		}
		
		fgets(line, 150, Name);
		printf(line);
		
		printf(": %d\n", t[a]);
		a++;
	
	}
			
	printf("\n");
	
	fclose(total_scor);
}


void level1_high_score (){
	
	int t[100];
	int n;
	int i;
	char *token;
	char help[256];
	char line[150];
	int a = 0;
	int b = 0;
	int j = 0;
	int k = 0;
	int temp;
	char tempc[20];
	char lst[50][20];
	
	FILE * Name = fopen("name.txt", "r");
	FILE * total_scor = fopen("level 1.txt", "r");
	
	fscanf(total_scor, "%s", help);
	
	token = strtok(help, ",");
	
	i = 0;
	while (token != NULL) {
		
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	
	n = i;
	
	while (!feof(Name)){
		
		if (a == n) {
			break;
		}
		
		fgets(line, 150, Name);
		
		for (b = 0; b < 20; b++){
			
			lst[a][b] = line[b];
	
		}
		
		a++;
	
	}
	
	fclose(total_scor);
	
	for (j = 0; j < n; j++){
		
		for (k = 0; k < n-j-1; k++){
			
			if (t[k] < t[k+1]){
				
				temp = t[k];
				t[k] = t[k+1];
				t[k+1] = temp;
				
				
				for (i = 0; i < 20; i++){
					tempc[i] = lst[k][i];
					lst[k][i] = lst[k+1][i];
					lst[k+1][i] = tempc[i];
				}
					
			}
			
		}
		
	}
	
	for (i = 0; i < n; i++){
		
		printf("%s: %d\n", lst[i], t[i]);
		
	}
}


void level1_score () {
	int t[100];
	int n;
	int i;
	
	char *token;
	char help[256];
	char line[150];
	int a = 0;
	
	FILE * Name = fopen("name.txt", "r");
	FILE * total_scor = fopen("level 1.txt", "r");
	
	fscanf(total_scor, "%s", help);
	
	token = strtok(help, ",");
	
	i = 0;
	while (token != NULL) {
		
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	
	n = i;
	
	while (!feof(Name)){
		
		if (a == n) {
			break;
		}
		
		fgets(line, 150, Name);
		printf(line);
		
		printf(": %d\n", t[a]);
		a++;
	
	}
			
	printf("\n");
	
	fclose(total_scor);
}


void level2_high_score (){
	
	int t[100];
	int n;
	int i;
	char *token;
	char help[256];
	char line[150];
	int a = 0;
	int b = 0;
	int j = 0;
	int k = 0;
	int temp;
	char tempc[20];
	char lst[50][20];
	
	FILE * Name = fopen("name.txt", "r");
	FILE * total_scor = fopen("level 2.txt", "r");
	
	fscanf(total_scor, "%s", help);
	
	token = strtok(help, ",");
	
	i = 0;
	while (token != NULL) {
		
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	
	n = i;
	
	while (!feof(Name)){
		
		if (a == n) {
			break;
		}
		
		fgets(line, 150, Name);
		
		for (b = 0; b < 20; b++){
			
			lst[a][b] = line[b];
	
		}
		
		a++;
	
	}
	
	fclose(total_scor);
	
	for (j = 0; j < n; j++){
		
		for (k = 0; k < n-j-1; k++){
			
			if (t[k] < t[k+1]){
				
				temp = t[k];
				t[k] = t[k+1];
				t[k+1] = temp;
				
				
				for (i = 0; i < 20; i++){
					tempc[i] = lst[k][i];
					lst[k][i] = lst[k+1][i];
					lst[k+1][i] = tempc[i];
				}
					
			}
			
		}
		
	}
	
	for (i = 0; i < n; i++){
		
		printf("%s: %d\n", lst[i], t[i]);
		
	}
}


void level2_score () {
	int t[100];
	int n;
	int i;
	
	char *token;
	char help[256];
	char line[150];
	int a = 0;
	
	FILE * Name = fopen("name.txt", "r");
	FILE * total_scor = fopen("level 2.txt", "r");
	
	fscanf(total_scor, "%s", help);
	
	token = strtok(help, ",");
	
	i = 0;
	while (token != NULL) {
		
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	
	n = i;
	
	while (!feof(Name)){
		
		if (a == n) {
			break;
		}
		
		fgets(line, 150, Name);
		printf(line);
		
		printf(": %d\n", t[a]);
		a++;
	
	}
			
	printf("\n");
	
	fclose(total_scor);
}


void level3_high_score (){
	
	int t[100];
	int n;
	int i;
	char *token;
	char help[256];
	char line[150];
	int a = 0;
	int b = 0;
	int j = 0;
	int k = 0;
	int temp;
	char tempc[20];
	char lst[50][20];
	
	FILE * Name = fopen("name.txt", "r");
	FILE * total_scor = fopen("level 3.txt", "r");
	
	fscanf(total_scor, "%s", help);
	
	token = strtok(help, ",");
	
	i = 0;
	while (token != NULL) {
		
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	
	n = i;
	
	while (!feof(Name)){
		
		if (a == n) {
			break;
		}
		
		fgets(line, 150, Name);
		
		for (b = 0; b < 20; b++){
			
			lst[a][b] = line[b];
	
		}
		
		a++;
	
	}
	
	fclose(total_scor);
	
	for (j = 0; j < n; j++){
		
		for (k = 0; k < n-j-1; k++){
			
			if (t[k] < t[k+1]){
				
				temp = t[k];
				t[k] = t[k+1];
				t[k+1] = temp;
				
				
				for (i = 0; i < 20; i++){
					tempc[i] = lst[k][i];
					lst[k][i] = lst[k+1][i];
					lst[k+1][i] = tempc[i];
				}
					
			}
			
		}
		
	}
	
	for (i = 0; i < n; i++){
		
		printf("%s: %d\n", lst[i], t[i]);
		
	}
}



void level3_score () {
	int t[100];
	int n;
	int i;
	
	char *token;
	char help[256];
	char line[150];
	int a = 0;
	
	FILE * Name = fopen("name.txt", "r");
	FILE * total_scor = fopen("level 3.txt", "r");
	
	fscanf(total_scor, "%s", help);
	
	token = strtok(help, ",");
	
	i = 0;
	while (token != NULL) {
		
		t[i] = atoi(token);
		token = strtok(NULL, ",");
		i++;
	}
	
	n = i;
	
	while (!feof(Name)){
		
		if (a == n) {
			break;
		}
		
		fgets(line, 150, Name);
		printf(line);
		
		printf(": %d\n", t[a]);
		a++;
	
	}
			
	printf("\n");
	
	fclose(total_scor);
}


char level1 (int ran, int pattern[4][3]){
	
	int d[] = {0, 0, 0};
	int pos;
	int ran_num;
	int i;
	int a;
	
	
	
	print_lst(pattern[ran], 3);
	
	pos = random(0, 2, 1);
	ran_num = random(1, 100, 1);
	

	
	if (ran == 2){
		if (!(ran_num % 2 == 0)){
			ran_num = ran_num / 2;
		}
	}
	
	if (ran == 0 && pos == 2){
		ran_num = check(ran_num);
	}
	
	
	d[pos] = ran_num;
	
	
	print_lst(d, 3);
	
	for (i = 0; i < 3; i = i + 1){
		if (d[i] == 0){
			printf("Enter Number at position %d: ", i);
			scanf("%d", &a);
			d[i] = a;
		}
		
	}
	
	
	print_lst(d, 3);
	
	if (ran == 0){
		if (d[0]*d[1] == d[2]){
			return '1';
		}
	} else if (ran == 1){
		if (d[0]+1 == d[1] && d[1]+1 == d[2]){
			return '1';
		}
	} else if (ran == 2){
		if (d[0]/d[1] == d[2]){
			return '1';
		}
	} else if (ran == 3){
		if (d[0]-15 == d[1] && d[1]-15 == d[2]){
			return '1';
		}
	}
	
	return '0';
	
	
}



char level2 (int ran, int pattern[4][4]){
	
	int d[] = {0, 0, 0, 0};
	int pos;
	int ran_num;
	int i;
	int a;
	int nums[] = {1, 2, 4, 9};
	
	
	
	print_lst(pattern[ran], 4);
	
	pos = random(0, 3, 1);
	ran_num = random(1, 100, 1);
	

	if (ran == 3){
		if (pos == 1){
			ran_num = nums[random(0, 3, 1)];
		} else {
			pos = 0;
			ran_num = random(1, 10, 1);
		}
		
	}
	

	
	d[pos] = ran_num;
	
	
	print_lst(d, 4);
	
	for (i = 0; i < 4; i = i + 1){
		if (d[i] == 0){
			printf("Enter Number at position %d: ", i);
			scanf("%d", &a);
			d[i] = a;
		}
		
	}
	
	
	print_lst(d, 4);
	
	if (ran == 0){
		if (d[0] + 4 == d[1] && d[1] + 8 == d[2] && d[2] + 16 == d[3]){
			return '1';
		}
	} else if (ran == 1){
		if (d[0] - 7 == d[1] && d[1] - 6 == d[2] && d[2] - 5 == d[3]){
			return '1';
		}
	} else if (ran == 2){
		if (d[0] / d[1] == d[2] && d[1] / d[2] == d[3]){
			return '1';
		}
	} else if (ran == 3){
		if (d[1]*d[1] == d[2] && d[0]*d[0] == d[1] && d[2]*d[2] == d[3]){
			return '1';
		}
	}
	
	return '0';
	
	
}



char level3 (int ran, int pattern[4][5]){
	
	int d[] = {0, 0, 0, 0, 0};
	int pos;
	int ran_num;
	int i;
	int a;
	
	
	
	print_lst(pattern[ran], 5);
	
	pos = random(0, 4, 1);
	ran_num = random(1, 100, 1);
	
	d[pos] = ran_num;
	
	
	print_lst(d, 5);
	
	for (i = 0; i < 5; i = i + 1){
		if (d[i] == 0){
			printf("Enter Number at position %d: ", i);
			scanf("%d", &a);
			d[i] = a;
		}
		
	}
	
	
	print_lst(d, 5);
	
	if (ran == 0){
		if (d[0] + 2 == d[2] && d[2] + 2 == d[4] && d[1] - 3 == d[3]){
			return '1';
		}
	} else if (ran == 1){
		if (d[0] == d[2] && d[2] == d[4] && d[1] - 2 == d[3]){
			return '1';
		}
	} else if (ran == 2){
		if (d[0] - 5 == d[1] && d[1] - 2 == d[2] && d[2] - 5 == d[3] && d[3] - 2 == d[4]){
			return '1';
		}
	} 
	
	return '0';
	
	
}



void main () {
	
	int num;
	char res;
	int ran;
	int i;
	char a;
	int lst[3];
	int lst1[3];
	int lst2[3];
	char name[20];
	char test;
	int run = 1;
	int rep;
	int dec;
	int pattern1[4][3] = {
						{4, 3, 12},
						{3, 4, 5},
						{36, 6, 6},
						{50, 35, 20}
	};
	int pattern2[4][4] = {
						{21, 25, 33, 49},
						{19, 12, 6, 1},
						{100, 10, 10, 1},
						{2, 4, 16, 256}
	};
	int pattern3[3][5] = {
						{13, 29, 15, 26, 17},
						{32, 31, 32, 29, 32},
						{36, 31, 29, 24, 22}
	};
	
	
	while (run == 1){
		
		int score = 0;
		int score2 = 0;
		int score3 = 0;
		int scoret = 0;
	
		FILE * main = fopen("main.txt", "a");
		FILE * Name = fopen("name.txt", "a");
		FILE * total = fopen("total.txt", "a");
		FILE * level_1 = fopen("level 1.txt", "a");
		FILE * level_2 = fopen("level 2.txt", "a");
		FILE * level_3 = fopen("level 3.txt", "a");
		
		printf("To get the report press 2, to play the game, press 1. To quit the game, press 0: ");
		scanf("%d", &rep);
		
		if (rep == 2){
			
			printf("What score do you want, press:\n0 for total score\n1 for level 1 score\n2 for level 2 score\n3 for level 3 score\n");
			printf("10 for total high scores\n11 for level 1 high scores\n12 for level 2 high scores\n13 for level 3 high scores\n");
			printf("100 for Number of times played by players\n");
			scanf("%d", &dec);
			
			if (dec == 0){
				
				total_score();
				
			} else if (dec == 1){
				
				level1_score();
				
			} else if (dec == 2){
				
				level2_score();
				
			} else if (dec == 3){
				
				level3_score();
				
			} else if (dec == 10){
				
				total_high_score ();
				
			} else if (dec == 11){
				
				level1_high_score ();
				
			} else if (dec == 12){
				
				level2_high_score ();
				
			} else if (dec == 13){
				
				level3_high_score ();
				
			} else if (dec == 100){
				
				nooftimes();
				
			}
			
			rep = 0;
			
		} else if (rep == 0){
		
			run = 0;

		} else {
			
			printf("\n");
		
			printf("Game Starting\n");
			
			printf("\n");
			
			printf("Enter your name: ");
			scanf("%s", &name);
			
			
			printf("Starting level 1________________________________\n");
			printf("\n");
			
			for (i = 0; i < 3; i++){
				ran = ran_num1 (3, lst);
				lst[i] = ran;
			}
			
			for (i = 0; i < 3; i++){
				
				
				printf("Attemt Number: %d\n", i + 1);
				
				a = level1(lst[i], pattern1);
				
				
				if (a == '1'){
					printf("correct\n");
					printf("\n");
					score ++;
					scoret++;
				} else {
					printf("Incorrect\n");
					printf("\n");
				}
	
			}
			
			printf("Your score is: %d\n", score);
			printf("\n");
			
			if (score == 3){
				printf("Advancing to level 2\n");
				printf("\n");
			} else {
				printf("Try Again\n");
				printf("\n");
			}
			
			if (score == 3){
				
				printf("Starting level 2________________________________\n");
				printf("\n");
			
				for (i = 0; i < 3; i++){
					ran = ran_num1 (3, lst1);
					lst1[i] = ran;
				}
				
				
				for (i = 0; i < 3; i++){
					
					
					printf("Attemt Number: %d\n", i + 1);
					
					a = level2(lst1[i], pattern2);
					
					if (a == '1'){
						printf("correct\n");
						printf("\n");
						score2 ++;
						scoret ++;
					} else {
						printf("Incorrect\n");
						printf("\n");
					}
				}
				
				printf("Your score is: %d\n", score2);
				printf("\n");
				
				if (score2 >= 2){
					printf("Advancing to level 3\n");
					printf("\n");
				} else if (a == '0') {
					printf("Try Again\n");
					printf("\n");
				}
			
			}
			
			if (score2 >= 2){
				printf("Starting level 3________________________________\n");
				printf("\n");
			
				for (i = 0; i < 3; i++){
					ran = ran_num1 (2, lst2);
					lst2[i] = ran;
				}
				
				
				for (i = 0; i < 3; i++){
					printf("\n");
					
					printf("Attemt Number: %d\n", i + 1);
					
					a = level3(lst2[i], pattern3);
					
					if (a == '1'){
						printf("correct\n");
						printf("\n");
						score3 ++;
						scoret ++;
					} else {
						printf("Incorrect\n");
						printf("\n");
					}
				}
				
				printf("Your score is: %d\n", score3);
				printf("\n");
				
				if (score3 >= 1){
					printf("You Won\n");
					printf("\n");
				} else if (a == '0') {
					printf("Try Again\n");
					printf("\n");
				}
				
			}
			
			
			struct info player = {
					.name1 = name,
					.notp = 2,
					.total = scoret,
					.level1 = score,
					.level2 = score2,
					.level3 = score3
			};
			
			fprintf(main, "%s, %d, %d, %d, %d\n", name, player.total, player.level1, player.level2, player.level3);
			fprintf(Name, "%s\n", name);
			fprintf(total, "%d,", scoret);
			fprintf(level_1, "%d,", score);
			fprintf(level_2, "%d,", score2);
			fprintf(level_3, "%d,", score3);
		
			
			fclose(main);
			fclose(Name);
			fclose(total);
			fclose(level_1);
			fclose(level_2);
			fclose(level_3);
			
			printf ("To play the game again or to get the report, press 1. To quit the game, press 0: ");
			
			scanf("%d", &run);
			
			printf("\n");
		
		}
		
	}

}
