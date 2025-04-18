/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:20:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 13:22:34 by yabukirento      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

// カラーコード
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

// テスト結果の追跡
int g_test_count = 0;
int g_test_passed = 0;

// 出力長さの比較と結果表示
void compare_length(int ft_len, int std_len, const char *test_name)
{
    g_test_count++;
    printf("出力長さ: ft_printf=%d, printf=%d ", ft_len, std_len);
    
    if (ft_len == std_len)
    {
        printf("[%s OK %s]\n", GREEN, RESET);
        g_test_passed++;
    }
    else
        printf("[%s KO %s] - %s長さが異なります%s\n", RED, RESET, RED, RESET);
}

// 各種フォーマット指定子のテスト
void test_format_specifiers(void)
{
    int ft_len;
    int std_len;
    
    printf("\n%s===== フォーマット指定子のテスト =====%s\n", BLUE, RESET);
    
    // %c テスト
    printf("\n%s----- %%c テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %c\n", 'A');
    std_len = printf("printf:    %c\n", 'A');
    compare_length(ft_len, std_len, "%c");
    
    // %s テスト
    printf("\n%s----- %%s テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %s\n", "Hello World");
    std_len = printf("printf:    %s\n", "Hello World");
    compare_length(ft_len, std_len, "%s");
    
    // %p テスト
    int num = 42;
    printf("\n%s----- %%p テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %p\n", &num);
    std_len = printf("printf:    %p\n", &num);
    compare_length(ft_len, std_len, "%p");
    
    // %d テスト
    printf("\n%s----- %%d テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %d\n", 12345);
    std_len = printf("printf:    %d\n", 12345);
    compare_length(ft_len, std_len, "%d");
    
    // %i テスト
    printf("\n%s----- %%i テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %i\n", -9876);
    std_len = printf("printf:    %i\n", -9876);
    compare_length(ft_len, std_len, "%i");
    
    // %u テスト
    printf("\n%s----- %%u テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %u\n", UINT_MAX);
    std_len = printf("printf:    %u\n", UINT_MAX);
    compare_length(ft_len, std_len, "%u");
    
    // %x テスト
    printf("\n%s----- %%x テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %x\n", 0xABCDEF);
    std_len = printf("printf:    %x\n", 0xABCDEF);
    compare_length(ft_len, std_len, "%x");
    
    // %X テスト
    printf("\n%s----- %%X テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %X\n", 0xabcdef);
    std_len = printf("printf:    %X\n", 0xabcdef);
    compare_length(ft_len, std_len, "%X");
    
    // %% テスト
    printf("\n%s----- %%%% テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %%\n");
    std_len = printf("printf:    %%\n");
    compare_length(ft_len, std_len, "%%");
}

// エッジケースのテスト
void test_edge_cases(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== エッジケースのテスト =====%s\n", BLUE, RESET);
    
    // NULLポインタ
    printf("\n%s----- NULL文字列テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %s\n", NULL);
    std_len = printf("printf:    %s\n", NULL);
    compare_length(ft_len, std_len, "NULL %s");
    
    // 空文字列
    printf("\n%s----- 空文字列テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %s\n", "");
    std_len = printf("printf:    %s\n", "");
    compare_length(ft_len, std_len, "empty %s");
    
    // INT_MIN
    printf("\n%s----- INT_MIN テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %d\n", INT_MIN);
    std_len = printf("printf:    %d\n", INT_MIN);
    compare_length(ft_len, std_len, "INT_MIN");
    
    // INT_MAX
    printf("\n%s----- INT_MAX テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %d\n", INT_MAX);
    std_len = printf("printf:    %d\n", INT_MAX);
    compare_length(ft_len, std_len, "INT_MAX");
    
    // NULLポインタ（%p）
    printf("\n%s----- NULL ポインタ（%%p）テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %p\n", NULL);
    std_len = printf("printf:    %p\n", NULL);
    compare_length(ft_len, std_len, "NULL %p");
}

// 複合フォーマットのテスト
void test_combined_formats(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== 複合フォーマットのテスト =====%s\n", BLUE, RESET);
    
    // 複合テスト1
    printf("\n%s----- 複合テスト1 -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: 文字[%c] 文字列[%s] 数値[%d] 16進数[%x]\n", 'Z', "test", 42, 255);
    std_len = printf("printf:    文字[%c] 文字列[%s] 数値[%d] 16進数[%x]\n", 'Z', "test", 42, 255);
    compare_length(ft_len, std_len, "複合1");
    
    // 複合テスト2
    printf("\n%s----- 複合テスト2 -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: 複数の数値: %d, %i, %u, %x, %X\n", 123, -456, 789, 255, 255);
    std_len = printf("printf:    複数の数値: %d, %i, %u, %x, %X\n", 123, -456, 789, 255, 255);
    compare_length(ft_len, std_len, "複合2");
}

// 連続したパーセント記号のテスト
void test_consecutive_percent(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== 連続したパーセント記号のテスト =====%s\n", BLUE, RESET);
    
    ft_len = ft_printf("ft_printf: %%%%%%\n");
    std_len = printf("printf:    %%%%%%\n");
    compare_length(ft_len, std_len, "連続%%");
}

// テスト結果のサマリーを表示
void print_summary(void)
{
    printf("\n%s===== テスト結果サマリー =====%s\n", BLUE, RESET);
    printf("実行テスト数: %d\n", g_test_count);
    
    if (g_test_passed == g_test_count)
    {
        printf("%s全テスト成功! %d/%d [100%%]%s\n", 
              GREEN, g_test_passed, g_test_count, RESET);
    }
    else
    {
        printf("%sテスト結果: %d/%d [%.1f%%] 成功%s\n", 
              (g_test_passed > g_test_count / 2) ? YELLOW : RED,
              g_test_passed, g_test_count,
              (g_test_passed * 100.0) / g_test_count, RESET);
    }
}

// 数値の特殊ケーステスト
void test_special_numbers(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== 数値の特殊ケーステスト =====%s\n", BLUE, RESET);
    
    // ゼロ値テスト
    printf("\n%s----- ゼロ値テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: 整数0[%d] 16進数0[%x][%X]\n", 0, 0, 0);
    std_len = printf("printf:    整数0[%d] 16進数0[%x][%X]\n", 0, 0, 0);
    compare_length(ft_len, std_len, "ゼロ値");
    
    // 負の16進数
    printf("\n%s----- 負の16進数テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %%x[%x] %%X[%X]\n", -42, -42);
    std_len = printf("printf:    %%x[%x] %%X[%X]\n", -42, -42);
    compare_length(ft_len, std_len, "負の16進数");
    
    // 大きな値
    printf("\n%s----- 大きな値テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %%u[%u] %%x[%x]\n", UINT_MAX, UINT_MAX);
    std_len = printf("printf:    %%u[%u] %%x[%x]\n", UINT_MAX, UINT_MAX);
    compare_length(ft_len, std_len, "大きな値");
}

// 特殊な文字列テスト
void test_special_strings(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== 特殊な文字列テスト =====%s\n", BLUE, RESET);
    
    // 非常に長い文字列
    char long_str[1000];
    for (int i = 0; i < 999; i++)
        long_str[i] = 'a' + (i % 26);
    long_str[999] = '\0';
    
    // 特殊文字を含む文字列
    printf("\n%s----- 特殊文字テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%s]\n", "タブ\t改行\n特殊文字");
    std_len = printf("printf:    [%s]\n", "タブ\t改行\n特殊文字");
    compare_length(ft_len, std_len, "特殊文字");
}

// 複数の連続変換指定子テスト
void test_consecutive_specifiers(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== 連続した変換指定子テスト =====%s\n", BLUE, RESET);
    
    printf("\n%s----- 連続指定子テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %d%s%c\n", 42, "test", '!');
    std_len = printf("printf:    %d%s%c\n", 42, "test", '!');
    compare_length(ft_len, std_len, "連続指定子");
    
    printf("\n%s----- 同一指定子連続テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %c%c%c%c\n", 'a', 'b', 'c', 'd');
    std_len = printf("printf:    %c%c%c%c\n", 'a', 'b', 'c', 'd');
    compare_length(ft_len, std_len, "同一指定子連続");
}

// 境界値テスト
void test_boundary_cases(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== 境界値テスト =====%s\n", BLUE, RESET);
    
    // 指定子のみ
    printf("\n%s----- 指定子のみテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: %d\n", 42);
    std_len = printf("printf:    %d\n", 42);
    compare_length(ft_len, std_len, "指定子のみ");
    
    // 空文字列フォーマット
    printf("\n%s----- 空文字列フォーマットテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("");
    std_len = printf("");
    compare_length(ft_len, std_len, "空文字列フォーマット");
    
    // 末尾%
    printf("\n%s----- 末尾%%テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: Test%");
    std_len = printf("printf:    Test%");
    printf("\n");  // 改行を追加
    compare_length(ft_len, std_len, "末尾%");
}

// エラー処理テスト (ft_printfによっては実装が異なる)
void test_error_handling(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== エラー処理テスト =====%s\n", BLUE, RESET);
    
    // 認識されないフォーマット指定子
    printf("\n%s----- 未知の指定子テスト -----%s\n", YELLOW, RESET);
    printf("※ このテストはft_printfの実装により結果が異なる場合があります\n");
    ft_len = ft_printf("ft_printf: %z\n");
    std_len = printf("printf:    %z\n");
    compare_length(ft_len, std_len, "未知の指定子");
    // 認識されないフォーマット指定子
    printf("\n%s----- 未知の指定子テスト ver2 -----%s\n", YELLOW, RESET);
    printf("※ このテストはft_printfの実装により結果が異なる場合があります\n");
    ft_len = ft_printf("ft_printf: %q\n");
    std_len = printf("printf:    %q\n");
    compare_length(ft_len, std_len, "未知の指定子");
}

// メイン関数内の呼び出し追加
int main(void)
{
    printf("\n%s***** ft_printf テストプログラム *****%s\n", BLUE, RESET);
    
    test_format_specifiers();
    test_edge_cases();
    test_combined_formats();
    test_consecutive_percent();
    
    // 追加テスト
    test_special_numbers();
    test_special_strings();
    test_consecutive_specifiers();
    test_boundary_cases();
    test_error_handling();
    
    print_summary();
    
    printf("\n%s***** テスト終了 *****%s\n\n", BLUE, RESET);
    return (0);
}