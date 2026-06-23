# OpenGL Studies

Repositório de estudos baseado no livro **"OpenGL: Uma Abordagem Prática e Objetiva"** de Marcelo Cohen e Isabel Harb.

Cada diretório corresponde a um conceito ou capítulo do livro, com código comentado e um README explicando o que foi aprendido.

## 🛠️ Ambiente

- **Linguagem:** C++
- **Build:** CMake
- **Bibliotecas:** GLFW · GLAD · GLM

## 📁 Estrutura

```
opengl-studies/
├── Exemplos do livro ex: Janelas/          # Criando uma janela com GLFW
└── assets/                                 # Texturas e modelos compartilhados
```

> A estrutura vai crescendo conforme o avanço no livro...

## 🚀 Como compilar

```bash
git clone https://github.com/HemannB/opengl-studies.git
cd opengl-studies/<capitulo>
cmake -B build
cmake --build build
./build/<executavel>
```

> Certifique-se de ter GLFW e GLAD instalados ou configure via vcpkg.

## 📖 Referência

Cohen, Marcelo. Harb, Isabel. *OpenGL: Uma Abordagem Prática e Objetiva*. Novatec.