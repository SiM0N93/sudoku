#ifndef LOGIN_H
#define LOGIN_H

/* deklaration der Prototypen */
ACCOUNT login(void);
int authentificationStatus( char cNickname[20], char cPassword[28] );
ACCOUNT getUser( char cNickname[20], char cPassword[28]);

#endif /* LOGIN_H */
