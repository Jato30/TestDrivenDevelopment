#include "catch.hpp"
#include "StringCalculator.hpp"

TEST_CASE("Testes de sucesso:"){
     SECTION("1 numero + quebra de linha"){
          REQUIRE(StringCalculator("17\n"));
          REQUIRE(StringCalculator("17\n\n"));
          REQUIRE(StringCalculator("17\n\n\n\n\n\n\n\n\n\n\n"));
     }
     SECTION("1 numero: quebra de linha antes do numero"){
          REQUIRE(StringCalculator("\n17\n"));
          REQUIRE(StringCalculator("\n\n17\n"));
          REQUIRE(StringCalculator("\n\n\n\n\n\n\n17\n"));
     }


     SECTION("2 numeros + quebra de linha"){
          REQUIRE(StringCalculator("8,9\n"));
          REQUIRE(StringCalculator("8,9\n\n"));
          REQUIRE(StringCalculator("8,9\n\n\n\n\n\n\n\n\n\n\n"));
     }
     SECTION("2 numeros: Quebra de linha antes do ultimo numero"){
          REQUIRE(StringCalculator("8,\n9\n"));
          REQUIRE(StringCalculator("8,\n\n9\n"));
          REQUIRE(StringCalculator("8,\n\n\n\n\n\n\n\n\n\n9\n"));
     }
     SECTION("2 numeros: Quebra de linha depois do primeiro numero"){
          REQUIRE(StringCalculator("8\n,9\n"));
          REQUIRE(StringCalculator("8\n\n,9\n"));
          REQUIRE(StringCalculator("8\n\n\n\n\n\n\n\n\n\n,9\n"));
     }
     SECTION("2 numeros: Quebra de linha antes do primeiro numero"){
          REQUIRE(StringCalculator("\n8,9\n"));
          REQUIRE(StringCalculator("\n\n8,9\n"));
          REQUIRE(StringCalculator("\n\n\n\n\n\n\n\n\n\n8,9\n"));
     }


     SECTION("3 numeros + quebra de linha"){
          REQUIRE(StringCalculator("1,7,9\n"));
          REQUIRE(StringCalculator("1,7,9\n\n"));
          REQUIRE(StringCalculator("1,7,9\n\n\n\n\n\n\n\n\n\n\n"));
     }
     SECTION("3 numeros: Quebra de linha antes do ultimo numero"){
          REQUIRE(StringCalculator("1,7,\n9\n"));
          REQUIRE(StringCalculator("1,7,\n\n9\n"));
          REQUIRE(StringCalculator("1,7,\n\n\n\n\n\n\n\n\n\n9\n"));
     }
     SECTION("3 numeros: Quebra de linha depois do segundo numero"){
          REQUIRE(StringCalculator("1,7\n,9\n"));
          REQUIRE(StringCalculator("1,7\n\n,9\n"));
          REQUIRE(StringCalculator("1,7\n\n\n\n\n\n\n\n\n\n,9\n"));
     }
     SECTION("3 numeros: Quebra de linha antes do segundo numero"){
          REQUIRE(StringCalculator("1,\n7,9\n"));
          REQUIRE(StringCalculator("1,\n\n7,9\n"));
          REQUIRE(StringCalculator("1,\n\n\n\n\n\n\n\n\n\n7,9\n"));
     }
     SECTION("3 numeros: Quebra de linha depois do primeiro numero"){
          REQUIRE(StringCalculator("1\n,7,9\n"));
          REQUIRE(StringCalculator("1\n\n,7,9\n"));
          REQUIRE(StringCalculator("1\n\n\n\n\n\n\n\n,7,9\n"));
     }
     SECTION("3 numeros: Quebra de linha antes do primeiro numero"){
          REQUIRE(StringCalculator("\n1,7,9\n"));
          REQUIRE(StringCalculator("\n\n1,7,9\n\n"));
          REQUIRE(StringCalculator("\n\n\n\n\n\n1,7,9\n"));
     }


     SECTION("Numero > 1000"){
          REQUIRE(StringCalculator("17,1000\n"));
          REQUIRE(StringCalculator("17,4193\n"));
     }


     SECTION("Numero nulo em alguma posicao"){
          REQUIRE(StringCalculator("0\n"));
          REQUIRE(StringCalculator("00,0\n"));
          REQUIRE(StringCalculator("0,0000,0\n"));

          REQUIRE(StringCalculator("0,17\n"));
          REQUIRE(StringCalculator("17,0\n"));
          REQUIRE(StringCalculator("0,008,9\n"));
          REQUIRE(StringCalculator("17,0,0\n"));
     }


     SECTION("Mais que 3 numeros, mas em linhas diferentes"){
          REQUIRE(StringCalculator("1,2,3\n,4,5,6,\n7\n"));
     }


     SECTION("Numeros iguais"){
          REQUIRE(StringCalculator("9,9\n"));
          REQUIRE(StringCalculator("6,6,6\n"));
     }

     SECTION("Numeros decrescentes"){
          REQUIRE(StringCalculator("9,8\n"));
          REQUIRE(StringCalculator("9,7,1\n"));
     }


     SECTION("Novo delimitador"){
          REQUIRE(StringCalculator("//[,]17\n"));
          REQUIRE(StringCalculator("//[,]8,9\n"));
          REQUIRE(StringCalculator("//[,]1,7,9\n"));

          REQUIRE(StringCalculator("//[;]17\n"));
          REQUIRE(StringCalculator("//[;]8;9\n"));
          REQUIRE(StringCalculator("//[;]1;7;9\n"));

          REQUIRE(StringCalculator("//[-----]17\n"));
          REQUIRE(StringCalculator("//[-----]8-----9\n"));
          REQUIRE(StringCalculator("//[-----]1-----7-----9\n"));

          REQUIRE(StringCalculator("//[!@#/]17\n"));
          REQUIRE(StringCalculator("//[!@#/]8!@#/9\n"));
          REQUIRE(StringCalculator("//[!@#/]1!@#/7!@#/9\n"));
     }
}

TEST_CASE("Testes de fracasso:"){
     SECTION("Numero negativo"){
          REQUIRE(StringCalculator("-17\n"));
          REQUIRE(StringCalculator("20,-10,-7\n"));
     }


     SECTION("Sem quebra de linha no final"){
          REQUIRE(StringCalculator("17"));
          REQUIRE(StringCalculator("\n17"));
     }
     SECTION("Caracteres invalidos"){
          REQUIRE(StringCalculator(",\n"));
          REQUIRE(StringCalculator("\n17 "));
          REQUIRE(StringCalculator("17 \n"));
          REQUIRE(StringCalculator("17,\n"));
          REQUIRE(StringCalculator(",17\n"));
          REQUIRE(StringCalculator("a17\n"));
          REQUIRE(StringCalculator("8,a,9\n"));
     }


     SECTION("Mais que 4 numeros por linha: "){
          REQUIRE(StringCalculator("3,4,4,3\n"));
          REQUIRE(StringCalculator("1,\n5,6,3,2\n"));
     }


     SECTION("Delimitador"){
          REQUIRE(StringCalculator("//[,]8;9\n"));
          REQUIRE(StringCalculator("//[,]1,7-9\n"));

          REQUIRE(StringCalculator("//[;]8,9\n"));
          REQUIRE(StringCalculator("//[;]1;7.9\n"));

          REQUIRE(StringCalculator("/[-----]17\n"));
          REQUIRE(StringCalculator("//[-----]1----7-----9\n"));

          REQUIRE(StringCalculator("//[!@#/]1!@#/7!@#9\n"));
     }
}
