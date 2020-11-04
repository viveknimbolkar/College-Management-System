// Credit:- Vivek Nimbolkar
//Student of SIPNA COLLEGE OF ENGINEERING & TECHNOLOGY



#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

struct student{								//student structure
	
	char student_firstname[20];
	char student_fathername[20];
	char student_sirname[20];
	char full_name[70];
	char email[60];
	char section[3];
	char password[20];
	int mobile_no;
	int roll_no;
	int dob;
	
}stud_detail;


struct teacher{								//Teacher structure
	char teacher_firstname[20];
	char teacher_middlename[20];
	char teacher_sirname[20];
	char teacher_full_name[70];
	char email[60];
	char degree[30];
	char password[10];
	int dob;
	int age;
	int mobile_no;
	int experience;
	
}teacher_detail;


struct institute{							//Institute structure
	
	char institute_name[50];
	char principle_name[30];
	char institute_email[60];
	char Password[20];
	char facilities[100];
		
		struct facilities{
			
			char canteen[3];
			char hostel[3];
			char library[3];
			char playground[3];
			char wifi[3];
			char uniform[3];
			char parking[3];
			char security[3];
			char transport[3];
			char lab[3];
			char internet_center[3];
			char medical[3]; 
			char CCTV[3];
			char auditorium[3];
			
		}college_facilities;
		
	int contact_no;
	int dostarting;
	int institute_id;
	char accredition[40];
		
}institute_detail;


struct forget_pwd{
	
	char email[20];
	char section[3];
	char mobile[12];
	char rollno[3];
	char first_nm[15];
	char last_nm[25];
	
}forgot;

//--------------------------------------Functions used in programs-------------------------------


void delay(int a){
	
	int i,k;
	for(i=1;i<a;i++){
		k=i;
	}
	
}

void clear(){
	system("cls");
}


void loading(){
	int i;
	for(i=1;i<=10;i++){
			delay(100000000);
			printf(".");
		}
}

void colr_green(){
	system("color a");
}

void colr_white(){
	system("color F");
}

void colr_aqua(){
	system("color B");
}

void colr_red(){
	system("color C");
}



//pattern function---------------------------------------------------------------------------------------------------
void pattern(void){
	
	printf("\n\n\n\n\t\t   ****     **        **        ********\n");	        delay(100000000);	colr_green();
			printf("\t\t  *         * *      * *        *       \n");           delay(100000000);
			printf("\t\t *          *   *  *   *        *       \n");  	 		delay(100000000);   colr_red();
			printf("\t\t *          *    *     *        *       \n");   		delay(100000000);
			printf("\t\t *          *          *        ********\n");   		delay(100000000);	colr_aqua();
			printf("\t\t *          *          *               *\n"); 			delay(100000000);
			printf("\t\t *          *          *               *\n"); 			delay(100000000);	colr_white();
			printf("\t\t  *         *          *               *\n"); 			delay(100000000);
			printf("\t\t   ****     *          *        ********\n");			delay(100000000);	colr_green();
	
	printf("\n\n\n\n\t\t\tCOLLEGE MANAGEMENT SYSTEM\n\n\n\n\n\n");
}




//main function ------------------------------------------------------------------------------------------------------

int main(){
	
//	system("mode 80");					This line is used to increase the screen size of program by removing this comment.
	
	pattern();
		
	delay(1000000000);

	int i, j, k, institute_choice, choice, stud_choice;
	
	char pwd1[10];
	char pwd2[10];
	char student_list_reading;
	char teacher_list_reading;
	char institute_read;
	char notice_read;
	char group_read;
	char grp_msg[1000];
	char searchResult[60];
	char pwdResult[20];
	char email[60];
	char note[1000];
	char ans[3]={'y','n','0'};
	int found=0;
	int found2=0;
	
	FILE *student_data, *institute_data, *teacher_data, *student_list, *fp, *institute, *add_notice;
	
	FILE *stud_name, *institute_name, *teacher_name, *institute_auth, *teacher_list, *group;
	
	main:           //main menu return
	
	colr_white();
	clear();
		
	printf("\t####################### MAIN MENU ########################");
	
	printf("\n\n\n\t\t\t1) STUDENT LOGIN\n\n\t\t\t2) INSTITUTE LOGIN \n\n\t\t\t3) ADD STUDENT\n\n\t\t\t4) ADD INSTITUTE \n\n\t\t\t5) STUDENT LIST \n\n\t\t\t6) ADD TEACHING STAFF\n\n\t\t\t7) FORGOT PASSWORD\n\n\t\t\t8] EXIT");	
	
	printf("\n\n\n\n\tEnter your choice(1/2/3/4/5/6/7/8):- ");
	
	scanf("%d",&choice);
	
	//main menu started-----------------------------------------------------------------------------------------------
	
	switch(choice){
		
		
		case 1:
			
			student:
			clear();
			colr_green();
			printf("\t##################### STUDENT LOGIN #######################");
			
			printf("\n\n\tENTER EMAIL:- ");
			scanf("%s",&searchResult);                   						//email authentication
			
				fp=fopen("user_auth.txt","rb");
					
					while(fread(&stud_detail,sizeof(stud_detail),1,fp)==1){
						if(strcmp(searchResult,stud_detail.email)==0){
							found=1;
							break;
						}
					}
					if(found==1){
						system("color a");
						printf("\n\t\tUser found!");
					}
					else
						printf("\n\t\tUSER NOT FOUND!");
						
						
						printf("\n\nENTER PASSWORD:- ");						//password authentication
						scanf("%s",&pwdResult);
					
					rewind(fp);
					while(fread(&stud_detail,sizeof(stud_detail),1,fp)==1){
						if(strcmp(pwdResult,stud_detail.password)==0){
							found2=1;
							break;
						}	
					}	
					if(found2==1){
							
							clear();
							printf("\t################ WELCOME %s###############",stud_detail.email);
							
							printf("\n\n\t1] MY DETAILS\n\n\t2] COLLEGE NOTICES\n\n\t3] MESSAGES\n\n\t4] ADD GROUP MESSAGE");
							printf("\n\n\n\t\tEnter your choice:- ");
							scanf("%d",&stud_choice);
							
							
						switch(stud_choice){
							
							case 1:
									printf("we are coming soon!");
									delay(1000000000);
								
								break;
								
							
							case 2:	
							
								clear();
								
								printf("\n########################## COLLEGE NOTICE ##########################\n\n\n\t");
								
								add_notice=fopen("notice.txt","r");
								
								if(add_notice==NULL){
									printf("Error in opening file...");
								}
								
								
								 while((notice_read=fgetc(add_notice)) != EOF){
									printf("%c",notice_read);
								}
								fclose(add_notice);
								
								//This is a single line comment of this project
								
								break;	
							
							
							case 3:
								
								clear(); //This is clear call to action
								printf("\t############################## GROUP MESSAGE ##########################");
								
								group=fopen("group_msg.txt","r");
					
									while((group_read=fgetc(group)) != EOF){
										printf("%c",group_read);
									}
						
								fclose(group);
					
									
								
							break;	
							
							case 4:
								clear();
								printf("\t############################## ADD GROUP MESSAGE ##########################");
								
								group=fopen("group_msg.txt","a+");
					
									gets(grp_msg);
									fprintf(group,"%s",grp_msg);
					
								fclose(group);
										
							break;	
							
							default:
								goto main;
						}			
					}
					else{
						printf("\n\t\t\tERROR IN USERNAME OR PASSWORD!");
						
						
						
					}
				fclose(fp);
				
				
				
						
				
			
		break;

//########################################	

		case 2:
			
			
			institute_login:
			clear();
			colr_aqua();
			printf("########################## WELCOME TO INSTITUTE LOGIN ##########################");
			printf("\n\n\t1] TEACHER LIST\n\n\t2] STUDENT LIST\n\n\t3] INSTITUTE DETAILS\n\n\t4] READ COLLEGE NOTICES\n\n\t5] ADD COLLEGE NOTICE\n\n\t6] READ GROUP MESSAGES\n\n\t7] ADD GROUP MESSAGES\n\n\t8] EXIT");
			printf("\n\n\t\t\tEnter your choice:- ");
			scanf("%d",&institute_choice);
			
			switch(institute_choice){
				
				case 1:
					
					clear();
					printf("\t#################### TEACHER's LIST ######################\n\n\n");
					
					teacher_list=fopen("teachers_database.txt","r");
					
						while ((teacher_list_reading = fgetc(teacher_list)) != EOF){
                        
						     printf("%c",teacher_list_reading);
        				
						}
						
					fclose(teacher_list);	
					
					printf("\n\n\n\t\tDo you want to exit? y/n ");
					scanf("%s",&ans);
					if(ans[0]=='y' || ans[1]=='n'){
						goto main;
					}
					else{
						goto institute_login;
					}
						
							
				break;
				
				//--------------------------------------
				case 2:
					clear();
					printf("\t################## STUDENT's LIST ####################\n\n\n");
						 
						student_list=fopen("student_list.txt","r");
					
						while ((student_list_reading = fgetc(student_list)) != EOF){
                        
						     printf("%c",student_list_reading);
        				
						}
					fclose(student_list);
					
					
					printf("\n\n\n\n\t\tDo you want to exit? y/n ");
					scanf("%s",&ans);
					if(ans[0]=='y' || ans[1]=='n'){
						goto main;
					}
					else{
						goto institute_login;
					}
					
					
							
					
					
				break;
				
				//-----------------------------------------
				case 3:
					clear();
					printf("\t################# ABOUT THIS INSTITUTE ###################\n\n\n");
					
						institute_data=fopen("institute_database.txt","r");
							
							while((institute_read=fgetc(institute_data)) != EOF){
								printf("%c",institute_read);
							}
						
						fclose(institute_data);
						
					printf("\n\n\n\n\t\tDo you want to exit? y/n ");
					scanf("%s",&ans);
					if(ans[0]=='y' || ans[1]=='n'){
						goto main;
					}
					else{
						goto institute_login;
					}
							
					
				break;	
				
				//-----------------------------------------
				case 4:
					
					clear();
					printf("\t################## READING COLLEGE NOTICE #####################\n\n\n");
					
						add_notice=fopen("notice.txt","r");
							while((notice_read=fgetc(add_notice)) != EOF){
								printf("%c",notice_read);
							}
						
						fclose(add_notice);
					
				printf("\n\n\n\n\t\tDo you want to exit? y/n ");
					scanf("%s",&ans);
					if(ans[0]=='y' || ans[1]=='n'){
						goto main;
					}
					else{
						goto institute_login;
					}
							
					
				break;
				
				//-----------------------------------------
				case 5:
					
					clear();
					printf("\t################# ADD A COLLEGE NOTICE ###################\n\n\n");
					
						add_notice=fopen("notice.txt","a+");
							
						
							printf("\n\n(Read carefully--> Add an underscore '_' in the end of every word. Otherwise your notice can cause error..)\n");
							printf("\n\n\n\tWrite from here...");
							scanf("%s",note);
							
							fprintf(add_notice,"%s",note);
						
						fclose(add_notice);
						
						
					printf("\n\n\n\n\t\tDo you want to exit? y/n ");
					scanf("%s",&ans);
					if(ans[0]=='y'){
						goto main;
					}
					else{
						goto institute_login;
					}		
						
				break;
				
				//-----------------------------------------
				case 6:
					
					clear();
					printf("\t################# READING GROUP MESSAGES  ####################\n\n\n");
					group=fopen("group_msg.txt","r");
					
						while((group_read=fgetc(group)) != EOF){
							printf("%c",group_read);
						}
						
					fclose(group);
					
					
					printf("\n\n\n\t\tDo you want to exit? y/n ");
					scanf("%s",&ans);
					if(ans[0]=='y' || ans[1]=='n'){
						goto main;
					}
					else{
						goto institute_login;
					}		
					
				break;
				
				//-----------------------------------------
				case 7:
				
					clear();
					printf("\t################# WRITING GROUP MESSAGES  ####################\n\n\n");
					
					group=fopen("group_msg.txt","a+");
					
						printf("\n\n(Read carefully--> Add an underscore '_' in the end of every word. Otherwise your notice can cause error..)\n");
						printf("\n\n\nWrite from here...");
						scanf("\n\t%s",grp_msg);
						
						fprintf(group,"%s",grp_msg);         //file writing
					
					fclose(group);
					
					printf("\n\n\n\t\tDo you want to exit? y/n ");
					scanf("%s",&ans);
					if(ans[0]=='y' || ans[1]=='n'){
						goto main;
					}
					else{
						goto institute_login;
					}
							
							
				break;
				
				
				case 8:
					goto main;
					
			}
			
		break;
			
//########################################			
		
		case 3:
			
			add_student:
				
			clear();
			colr_white();
			printf("#################### ADD STUDENT INFORMATION ######################");
			
			printf("\n\n\n\t1] STUDENT FIRSTNAME:- ");
			scanf("%s",&stud_detail.student_firstname);
			
			printf("\n\n\t2] STUDENT FATHERNAME:- ");
			scanf("%s",&stud_detail.student_fathername);
			
			printf("\n\n\t3] STUDENT SIRNAME:- ");
			scanf("%s",&stud_detail.student_sirname);
																					//Name Contating (Full name making)
			for(i=0; stud_detail.student_firstname[i] != '\0';i++){
				
				stud_detail.full_name[i] = stud_detail.student_firstname[i];
			}
			stud_detail.full_name[i] = ' ';
			
			for(j=0; stud_detail.student_fathername[j] != '\0'; j++){
				
				stud_detail.full_name[i+j+1] = stud_detail.student_fathername[j]; 
			}
			stud_detail.full_name[i+j+1] = ' ';
			
			for(k=0; stud_detail.student_sirname[k] != '\0'; k++){
				
				stud_detail.full_name[i+j+k+2] = stud_detail.student_sirname[k];
			}
			stud_detail.full_name[i+j+k+2] = '\0';
			
			printf("\n\n\t5] ROLL NO:- ");
			scanf("%d",&stud_detail.roll_no);
			
			printf("\n\n\t6] SECTION:- ");
			scanf("%s",&stud_detail.section);
			
			printf("\n\n\t7] MOBILE NO:- ");
			scanf("%d",&stud_detail.mobile_no);
			
			printf("\n\n\t8] EMAIL ADDRESS:- ");
			scanf("%s",&stud_detail.email);
			
			printf("\n\n\t9] DATE OF BIRTH(dd/mm/yyy):- ");
			scanf("%d",&stud_detail.dob);
			
				while(strcmp(pwd1,pwd2)!=0){
					printf("\n\n\tEnter password:- ");
					scanf("%s",pwd1);
					printf("\n\n\tConfirm password:- ");
					scanf("%s",pwd2);
					
					if(strcmp(pwd1,pwd2) != 0){
						printf("\nPassword dosent't Matched!\tPlease try again!");
					}
					else
					  printf("Password Matched!");
				}
			
			strcpy(stud_detail.password,pwd1);
			
			
                                  ////storing database of student (common file) in file
			
			student_data=fopen("student_database.txt","a+");
			
				fprintf(student_data,"STUDENT NAME :- %s %s %s\n",stud_detail.student_firstname,stud_detail.student_fathername,stud_detail.student_sirname);
			
				fprintf(student_data,"EMAIL		   :- %s\n",stud_detail.email);
			
				fprintf(student_data,"PASSWORD	   :- %s\n",&stud_detail.password);
			
				fprintf(student_data,"MOBILE NO    :- %d\n",&stud_detail.mobile_no);
			
				fprintf(student_data,"DATE OF BIRTH:- %d\n",&stud_detail.dob);
			
				fprintf(student_data,"SECTION	   :- %s\n",&stud_detail.section);
			
				fprintf(student_data,"ROLL NO      :- %d\n_________________________________________________\n",&stud_detail.roll_no);   
			
			fclose(student_data);
			
			
			//-----------------------------making of student list (only name and email of students) in text file--------
			
			student_list=fopen("student_list.txt","a+");
				
				fprintf(student_list,"%s\t\t%s\n",stud_detail.full_name,stud_detail.email);
				
			fclose(student_list);
			
			
			//------------------------------student file name making for storing email address and password------
			
			stud_name=fopen("user_auth.txt","a+");
			
				fwrite(&stud_detail,sizeof(stud_detail),1,stud_name);
			
				
			fclose(stud_name);
			
			printf("\n\n\t\tDo you want to exit? y/n ");
			scanf("%s",&ans);
					if(ans[0]=='y' || ans[1]=='n'){
						goto main;
					}
					else{
						goto add_student;
					}
			
							
			
		break;		
			
			
//##########################################
			
			case 4:
				
				add_institute:
				clear();
				colr_aqua();
				printf("\t\t#################### ADD INSTITUTE DETAILS #####################");
				
				printf("\n\n\n\t1] INSTITUTE NAME:- ");
				gets(institute_detail.institute_name);
				
				printf("\n\n\t2] PRINCIPLE NAME:- ");
				gets(institute_detail.principle_name);
				
				printf("\n\n\t4] EMAIL:- ");
				scanf("%s",&institute_detail.institute_email);
				
				printf("\n\n\t5] ACCERIDATION:- ");
				scanf("%s",&institute_detail.accredition);
				
					while(strcmp(pwd1,pwd2)!=0){
						printf("\n\n\tEnter password:- ");
						scanf("%s",pwd1);
						printf("\n\n\tConfirm password:- ");
						scanf("%s",pwd2);
					
						if(strcmp(pwd1,pwd2) != 0){
						printf("\nPassword dosent't Matched!\tPlease try again!");
						}
						else
					 	 printf("Password Matched!");
					}	
			
					strcpy(institute_detail.Password,pwd1);
				
				printf("\n\n\t 7] CONTACT NO:- ");
				scanf("%d",&institute_detail.contact_no);
				
				printf("\n\n\t8] INSTITUTE ID:- ");
				scanf("%d",&institute_detail.institute_id);
				
				printf("\n\n\t9] STARTING DATE OF INSTITUTE:- ");
				scanf("%d",&institute_detail.dostarting);
				
				
				printf("\n\n\t8] COLLEGE FACILITIES:- (Enter 'y' for YES & 'n' for NO)\n\n");
				
					printf("\t\ta) Canteen: ");
					scanf("%s",&institute_detail.college_facilities.canteen);
		
					printf("\t\tb) Hostel: ");
					scanf("%s",&institute_detail.college_facilities.hostel);
					
					printf("\t\tc) Library: ");
					scanf("%s",&institute_detail.college_facilities.library);
					
					printf("\t\td) Playground: ");
					scanf("%s",&institute_detail.college_facilities.playground);
					
					printf("\t\te) Wifi: ");
					scanf("%s",&institute_detail.college_facilities.wifi);
					
					printf("\t\tf) Uniform: ");                                   /// College facilities
					scanf("%s",&institute_detail.college_facilities.uniform);
					
					printf("\t\tg) Parking: ");
					scanf("%s",&institute_detail.college_facilities.parking);
					
					printf("\t\th) Security: ");
					scanf("%s",&institute_detail.college_facilities.security);
					
					printf("\t\ti) Transport: ");
					scanf("%s",&institute_detail.college_facilities.transport);
					
					printf("\t\tj) Labs: ");
					scanf("%s",&institute_detail.college_facilities.lab);					
				
					printf("\t\tk) Internet PC's: ");
					scanf("%s",&institute_detail.college_facilities.internet_center);
				
					printf("\t\tl) Medical emergency: ");
					scanf("%s",&institute_detail.college_facilities.medical);
				
					printf("\t\tm) Vehical Parking: ");
					scanf("%s",&institute_detail.college_facilities.parking);
			
			
				                  //storing institute data
								  				
				institute_data=fopen("institute_database.txt","w");
				
					fprintf(institute_data,"\nINSTITUTE NAME  :- %s",institute_detail.institute_name);
					fprintf(institute_data,"\nPRINCIPLE NAME  :- %s",institute_detail.principle_name);
					fprintf(institute_data,"\nEMAIL			  :- %s",institute_detail.institute_email);
					fprintf(institute_data,"\nACCEIDRATION	  :- %s",institute_detail.accredition);
					fprintf(institute_data,"\nPASSWORD		  :- %s",institute_detail.Password);
					fprintf(institute_data,"\nDATE OF STARTING:- %d",institute_detail.dostarting);
					fprintf(institute_data,"\nINSTITUTE ID	  :- %d",institute_detail.institute_id);
					fprintf(institute_data,"\nCONTACT NO	  :- %d",institute_detail.contact_no);
					fprintf(institute_data,"\nCOLLEGE FACILITIES:-");
						fprintf(institute_data,"\nCafeteria      :- %s",institute_detail.college_facilities.canteen);
						fprintf(institute_data,"\tHostel         :- %s",institute_detail.college_facilities.hostel);
						fprintf(institute_data,"\tPlayground     :- %s",institute_detail.college_facilities.playground);
						fprintf(institute_data,"\tWi-Fi          :- %s",institute_detail.college_facilities.wifi);
						fprintf(institute_data,"\tLibrary		 :- %s",institute_detail.college_facilities.library);
						fprintf(institute_data,"\tUniform		 :- %s",institute_detail.college_facilities.uniform);            //College facilities
						fprintf(institute_data,"\tVehical Parking:- %s",institute_detail.college_facilities.parking);
						fprintf(institute_data,"\tSecurity       :- %s",institute_detail.college_facilities.security);
						fprintf(institute_data,"\tTransport		 :- %s",institute_detail.college_facilities.transport);
						fprintf(institute_data,"\tPractical Labs :- %s",institute_detail.college_facilities.lab);
						fprintf(institute_data,"\tInternet PC's  :- %s",institute_detail.college_facilities.internet_center);
						fprintf(institute_data,"\tMedical Room   :- %s",institute_detail.college_facilities.medical);
						fprintf(institute_data,"\tCCTV           :- %s",institute_detail.college_facilities.CCTV);
					
				
				fclose(institute_data);
				
	///  Storing institute database for authentacation purpose...........
				
				institute=fopen("institute_auth.txt","w");
				
					fwrite(&institute_detail,sizeof(institute_detail),1,institute);
					
				fclose(institute);
			
					printf("\n\n\n\t\tDo you want to exit? y/n ");
					scanf("%s",&ans);
					if(ans[0]=='y' || ans[1]=='n'){
						goto main;
					}
					else{
						goto add_institute;
					}	
			
			break;	
			
//########################################

			
			case 5:
				
				student_list:
				clear();
				colr_white();
				printf("###################### STUDENT's LIST ######################\n\n\nNAME OF STUDENT\t\t\t\tEMAIL ADDRESS\n\n");	

					student_list=fopen("student_list.txt","r");
					
						while ((student_list_reading = fgetc(student_list)) != EOF){
                        
						     printf("%c",student_list_reading);
        				
						}
						
					fclose(student_list);	
					
					printf("\n\n\n\t\tDo you want to exit? y/n ");
					scanf("%s",&ans);
					if(ans[0]=='y' || ans[1]=='n'){
						goto main;
					}
					else{
						goto student_list;
					}
							
					
			break;	
			
				
//##########################################			
			
			
			case 6:
			
				add_teacher:
				clear();
				colr_aqua();
				printf("############################## ADD TEACHING STAFF ##############################");		
				
				printf("\n\n\n\t1] FIRSTNAME:- ");
				scanf("%s",&teacher_detail.teacher_firstname);
				
				printf("\n\n\t2] MIDDLENAME:- ");
				scanf("%s",&teacher_detail.teacher_middlename);
				
				printf("\n\n\t3] SIRNAME:- ");
				scanf("%s",&teacher_detail.teacher_sirname);
																			//string concatination
				for(i=0; teacher_detail.teacher_firstname[i] != '\0';i++){
				
					teacher_detail.teacher_full_name[i] = teacher_detail.teacher_firstname[i];
			    }
				teacher_detail.teacher_full_name[i] = ' ';
			
				for(j=0; teacher_detail.teacher_middlename[j] != '\0'; j++){
				
					teacher_detail.teacher_full_name[i+j+1] = teacher_detail.teacher_middlename[j]; 
				}
				teacher_detail.teacher_full_name[i+j+1] = ' ';
			
				for(k=0; teacher_detail.teacher_sirname[k] != '\0'; k++){
				
					teacher_detail.teacher_full_name[i+j+k+2] = teacher_detail.teacher_sirname[k];
				}
				teacher_detail.teacher_full_name[i+j+k+2] = '\0';
				
				do{
					printf("\n\n\t4] DEGREE:- ");
					scanf("%s",&teacher_detail.degree);
					
					printf("\n\t\tDo you have another degree?");
					scanf("%s",&ans);
					
				}while(ans[0]=='y' && ans[1] != 'n');
				
				printf("\n\n\t5] YEAR OF EXPERIENCE:- ");
				scanf("%d",&teacher_detail.experience);
				
				printf("\n\n\t6] AGE:- ");
				scanf("%d",&teacher_detail.age);
				
				printf("\n\n\t7] DATE OF BIRTH:- ");
				scanf("%d",&teacher_detail.dob);
				
				printf("\n\n\t8] EMAIL:- ");
				scanf("%s",&teacher_detail.email);
				
					while(strcmp(pwd1,pwd2)!=0){
						printf("\n\n\tEnter password:- ");
						scanf("%s",pwd1);
						printf("\n\n\tConfirm password:- ");
						scanf("%s",pwd2);
					
						if(strcmp(pwd1,pwd2) != 0){
						printf("\nPassword dosent't Matched!\tPlease try again!");
						}
						else
					  	printf("Password Matched!");
					}	
			
					strcpy(teacher_detail.password,pwd1);
				
				printf("\n\n\t10] MOBILE NO:- ");
				scanf("%d",&teacher_detail.mobile_no);
				
				//  storing database of teachers
				
				teacher_data=fopen("teachers_database.txt","a+");
					
					fprintf(teacher_data,"\nFULLNAME:- %s",teacher_detail.teacher_full_name);
					fprintf(teacher_data,"\nMOBILE NO:- %d",teacher_detail.mobile_no);
					fprintf(teacher_data,"\nDEGREE:- %s",teacher_detail.degree);
					fprintf(teacher_data,"\nEXPERIENCE:- %d",teacher_detail.experience);
					fprintf(teacher_data,"\nAGE:- %d",teacher_detail.age);
					fprintf(teacher_data,"\nDATE OF BIRTH:- %d",teacher_detail.dob);
					fprintf(teacher_data,"\nEMAIL:- %s",teacher_detail.email);
					fprintf(teacher_data,"\nPASSWORD:- %s\n_____________________________________________________________",teacher_detail.password);
					
				fclose(teacher_data);	
				
				printf("\n\n\n\t\tDo you want to exit? y/n ");
					scanf("%s",&ans);
					if(ans[0]=='y' || ans[1]=='n'){
						goto main;
					}
					else{
						goto add_teacher;
					}
			
							
							
			break;	
				
//##############################################

			
			case 7:
				
				forgot_password:
				clear();
				colr_red();
				printf("############################## FORGOT PASSWORD ##############################");					
				
				printf("\n\n\n1) FIRSTNAME:- ");
				scanf("%s",forgot.first_nm);
				
				printf("\n2) LASTNAME:- ");
				scanf("%s",forgot.last_nm);
				
					strcat(forgot.first_nm,forgot.last_nm);
				
				
				printf("\n3) EMAIL:- ");
				scanf("%s",forgot.email);
				
				printf("\n4) ROLL NO:- ");
				scanf("%s",forgot.rollno);
				
				printf("\n5) MOBILE NO:- ");
				scanf("%s",forgot.mobile);
				
				printf("\n6) SECTION:- ");
				scanf("%s",forgot.section);
				
				printf("\n\n\nOkay! Please contact your respective class teacher for getting your password.\n\nWe keep your account secured.  :-)");
				
			
					printf("\n\n\n\t\tDo you want to exit? y/n ");
					scanf("%s",&ans);
					if(ans[0]=='y' || ans[1]=='n'){
						goto main;
					}
					else{
						goto forgot_password;
					}
						
				
			break;	
//###############################			
			
			case 8:
				clear();
				goto end;
				break;
//##############################			
			default:
				clear();
				printf("Thanks for using us!");	
				break;
				
						
	} //-------------------------------------------switch is closed here---------------------------------------
	
	
	end:
		clear();
		system("color a");
		printf("\n\n\n\n\n\n\n\t\t\tSAVING DATABASE"); loading();
		printf("\n\n\t\t\tCHEACKING FOR ERRORS");loading();
		printf("\n\n\t\t\tCLOSING PROGRAM");loading();
		
		
	
	
	return 0;
	
	

}
