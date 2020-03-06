/**
 *  @judge NTUJ
 *  @id 1355
 *  @tag DP
 */
��# i n c l u d e   < s t d i o . h >  
 # i n c l u d e   < s t r i n g . h >  
 # i n c l u d e   < s t d l i b . h >  
 # i n c l u d e   < i o s t r e a m >  
 # d e f i n e   N   3 1  
 u s i n g   n a m e s p a c e   s t d ;  
  
 d o u b l e   w l e n [ N ] ,   b l e n [ N ] ;  
 d o u b l e   w D P [ N ] [ N   *   N ] ,   b D P [ N ] [ N   *   N ] ;  
 d o u b l e   a n s [ N ] [ N   *   N ] ;  
 / / F [ i , j ]   =   ( L e n [ i ] - j + 1 ) * F [ i - 1 , j - 1 ]   +   F [ i - 1 , j ]  
  
 i n l i n e   v o i d   I n i t ( d o u b l e   l e n [ N ] ,   d o u b l e   D P [ N ] [ N   *   N ] )  
 {  
 	 i n t   i ,   j ;  
 	 m e m s e t ( D P ,   0 ,   s i z e o f ( D P ) ) ;  
 	 f o r   ( i   =   0 ;   i   < =   N   -   1 ;   i + + )   D P [ i ] [ 0 ]   =   1 ;  
 	 f o r   ( i   =   1 ;   i   < =   N   -   1 ;   i + + )  
 	 	 f o r   ( j   =   1 ;   j   < =   l e n [ i ] ;   j + + )  
 	 	 	 D P [ i ] [ j ]   =   ( l e n [ i ]   -   j   +   1 )   *   D P [ i   -   1 ] [ j   -   1 ]   +   D P [ i   -   1 ] [ j ] ;  
 	 r e t u r n   ;  
 }  
  
 i n t   m a i n ( )  
 {  
 	 i n t   i ,   j ,   k ;  
 	 w l e n [ 0 ]   =   - 1 ,   w l e n [ 1 ]   =   1 ;  
 	 b l e n [ 0 ]   =   0 ,   b l e n [ 1 ]   =   2 ;  
 	 f o r   ( i   =   2 ;   i   < =   N   -   1 ;   i + + )  
 	 {  
 	 	 w l e n [ i ]   =   w l e n [ i   -   2 ]   +   2 ;  
 	 	 b l e n [ i ]   =   b l e n [ i   -   2 ]   +   2 ;  
 	 }  
 	 I n i t ( w l e n ,   w D P ) ;  
 	 I n i t ( b l e n ,   b D P ) ;  
 	 m e m s e t ( a n s ,   0 ,   s i z e o f ( a n s ) ) ;  
 	 f o r   ( i   =   1 ;   i   < =   N   -   1 ;   i + + )  
 	 {  
 	 	 f o r   ( j   =   1 ;   j   < =   ( N   -   1 )   *   ( N   -   1 ) ;   j + + )  
 	 	 	 f o r   ( k   =   0 ;   k   < =   j ;   k + + )  
 	 	 	 	 i f   ( k   < =   w l e n [ i ]   & &   j   -   k   < =   b l e n [ i   -   1 ] )  
 	 	 	 	 	 a n s [ i ] [ j ]   + =   w D P [ i ] [ k ]   *   b D P [ i   -   1 ] [ j   -   k ] ;  
 	 }  
 	 w h i l e   ( s c a n f ( " % d   % d " ,   & i ,   & j )   ! =   E O F )  
 	 {  
 	 	 i f   ( i   = =   0   & &   j   = =   0 )   b r e a k ;  
 	 	 p r i n t f ( " % . l f \ n " ,   a n s [ i ] [ j ] ) ;  
 	 }  
 } 