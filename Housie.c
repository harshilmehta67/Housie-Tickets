// AUTHOR : Harshil Mehta
// Date: 23.05.2020
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int ticket[3][9] ;
int max_slots = 15 ;
int to_be_filled[3][9] ;
int i , j , k;

void printTicket(int mat[3][9]) {
	for(i = 0 ; i < 3 ; i ++) {
		for(j = 0 ; j < 9 ; j ++) {
			printf("%4d ",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void fillRandomly() {
	int filled = 0 ;
	for(i = 0 ; i < 9 ; i ++) {
		// keeping 1 number in column (base case)
		j = rand() % 3 ;
		to_be_filled[j][i] = 1;
		filled ++ ;
	}
	while(filled < max_slots) {
		for(i = 0 ; i < 9 ; i++) {
			// Now, filling for each column randomly
			j = rand() % 3 ;
			if(!to_be_filled[j][i]) {
				to_be_filled[j][i] = 1;
				filled ++ ;
			}
			// In case slots are filled already
			if(filled == max_slots) {
				break ;
			}
		}
	}
}
void orderTicket(){
	int temp = 0;
	for(i = 0 ; i < 9 ; i ++){
		for(j = 0 ; j < 3 ; j ++){
			// Using Bubble sort to sort columns
			if(ticket[j][i] != 0){
				for(k = j ; k < 3 ; k ++){
					if(ticket[k][i] < ticket[j][i] && ticket[k][i] != 0){
						temp = ticket[j][i] ;
						ticket[j][i] = ticket[k][i] ;
						ticket[k][i] = temp ;
					}
				}
			}
		}
	}
}
void removeRedundancy(){
	for(i = 0 ; i < 9 ; i ++){
		for(j = 0 ; j < 3 ; j ++){
			if(ticket[j][i] != 0){
				for(k = j + 1 ; k < 3 ; k ++){
					if(ticket[k][i] != 0){
						while(ticket[k][i] == ticket[j][i]){
							ticket[j][i] = to_be_filled[j][i] * (rand() % (10) + (10*i));
						}
					}
				}
			}
		}
	}
}
void clearPrev(){
	for(i = 0 ;i < 3 ; i ++){
		for(j = 0 ;j < 9 ; j ++){
			to_be_filled[i][j] = 0 ;
			ticket[i][j] = 0 ;
		}
	}
}
void generateTicket() {
	fillRandomly();
	for(i = 0; i < 3 ; i ++) {
		for(j = 0 ; j < 9 ; j ++) {
			// fill numbers column - wise
			ticket[i][j] = to_be_filled[i][j] * (rand() % (10) + (10*j));
		}
	}
	removeRedundancy();
	orderTicket();
	printTicket(ticket);
	clearPrev();
}
int createUser(){
	int userno = srand(time(0));
	return userno;
}
int main() {
	// no. of tickets you want
	srand(time(0));
	int t = 4;
	while(t--) {
		generateTicket();
	}
	return 0;
}
