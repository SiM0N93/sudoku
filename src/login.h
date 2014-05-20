#ifndef LOGIN_H
#define LOGIN_H

/* deklaration der Prototypen */
ACCOUNT login(void);
int authentificationStatus( char cNickname[], char cPassword[] );
ACCOUNT getUser( char cNickname[], char cPassword[]);

#endif /* LOGIN_H */
