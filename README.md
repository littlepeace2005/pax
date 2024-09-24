# The Pax Programming Language
Pax is a high-level, general-purpose programming language with an intuitive syntax and powerful capabilities.


## Fundamentals
A Pax program is a sequence of source code that contains declarations, executed on an open-source interpreter.

### Source character set
The basic source character set consists of 96 characters:
- the space character;
- the control characters that represent horizontal tab, vertical tab, form feed, and new line;
- the 26 uppercase letters in the Latin alphabet<br/>
```A B C D E F G H I J K L M N O P Q R S T U V W X Y Z```;
- the 26 lowercase letters in the Latin alphabet<br/>
```ab c d e f g h i j k l m n o p q r s t u v w x y z```;
- the 10 decimal digits<br/>
```0 1 2 3 4 5 6 7 8 9```;
- the following 29 graphic characters<br/>
```! " # % & ' ( ) * + , - . / : ; < = > ? [ \ ] ^ _ { | } ~```.

### Comments
Comments serve as in-code documentation that shall be ignored by the interpreter.<br/>
- Multi-line comment: <code>/* <i>comment</i> */</code>
- Single-line comment: <code>// <i>comment</i></code>

## Statements
Statements are fragments of a Pax program that shall be executed in sequence.

### Expression statements
An expression statement is an expression followed by a semicolon.
- <code><i>expression<sub>(optional)</sub></i> ;</code>
