# get_next_line

> Projeto da 42 Lisboa

---

## 📝 Descrição
Este projeto tem como objetivo implementar uma função chamada `get_next_line` que permite ler um arquivo linha por linha de forma eficiente e segura. É um desafio clássico em C que exige compreensão aprofundada de buffers, leitura com `read()`, alocação dinâmica e gerenciamento de múltiplos file descriptors.

---

## ⚙️ Funcionalidades
- Leitura de uma linha por chamada, até encontrar '\n' ou EOF
- Suporte a vários file descriptors abertos simultaneamente *(bônus)*
- Uso de buffer dinâmico definido por `BUFFER_SIZE`
- Implementação seguindo as normas da 42 (Norminette)

---

## 📂 Arquivos do Projeto
```
get_next_line/
├── get_next_line.c         // Lógica principal da leitura
├── get_next_line_utils.c   // Funções auxiliares (libft-like)
├── get_next_line.h         // Headers e protótipos
└── Makefile                // Compilação automatizada
```

---

## 🧪 Compilando e Testando

### 🔨 Compilar com Makefile
```bash
make
```

### 🧪 Exemplo de main de teste:
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("arquivo.txt", O_RDONLY);
    char *linha;

    while ((linha = get_next_line(fd)) != NULL)
    {
        printf("%s", linha);
        free(linha);
    }
    close(fd);
    return (0);
}
```

### 🖼️ Prints dos Testes
![Teste 1](./img/teste_get_next_line_1.png)
![Teste 2](./img/teste_get_next_line_2.png)

---

## 🚫 Regras da 42
- ❗ **Proibido usar**: `strjoin` da libc, `malloc` com leaks, `read` com tamanho zero
- ✅ Seguindo as regras da Norminette
- 📚 Funções auxiliares foram implementadas manualmente

---

## 🧠 Estrutura e Lógica
- Cada chamada de `get_next_line` retém o que já foi lido
- Utiliza um buffer estático ou lista ligada para salvar restos *(bônus)*
- Divide a leitura em:
  - Leitura com `read()`
  - Salvamento temporário (restos)
  - Montagem da linha

---

## 👨‍💻 Autor
**Lucas C. M. L.**
- 📫 lucascml.dev@outlook.com
- 🌍 Lisboa, Portugal (disponível para toda a UE)
- 🌐 [GitHub - lucascml](https://github.com/lucascml)

---

> Projeto feito com foco em aprendizado de gestão de memória, leitura em C e estruturas de dados.

