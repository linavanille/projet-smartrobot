# Convention de nommage

## Constantes

Les constantes sont écrites en majuscules entièrement pour pouvoir les différencier.

> **Regex :**
> ```regex
> [A-Z]+
> ```

> **Exemple :**
> ``` c
> const int CONSTANTE = 10;
> ```

## Fonctions

Les fonctions sont écrites en CamelCase.

> **Regex :**
> ```regex
> [a-z][a-zA-Z]+
> ```

> **Exemple :**
> ``` c
> int maxInt(int, int);
> ```

### Cas des retours booléens

Pour un retour Booléen, les fonctions doivent commencer par un `est`, ou un `sont` en fonction des valeurs testées.

> **Regex :**
> ```regex
> (est|sont)[A-Z][a-zA-Z]+
> ```

> **Exemple :**
> ``` c
> bool estPair(int);
> ```

## Accolades

Les accolades sont placées dans leur lignes seules, à la même indentation pour l'ouvrante et la fermante, et engendrent une indentation.

> **Regex :**
> ```regex
> \t{n}\{\n(\t{n+1}[^\n]*\n)*\t{n}\}
> ```
> En prenant `n` l'indentation courante.

> **Exemple :**
> ``` c
> {
>   /*Du code…*/
> }
> ```

## Espaces de nommage

Les espaces de nommage sont placés avant chaque nom de fonctions, variables globales et constante du fichier qui les définits.