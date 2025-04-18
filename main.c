/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabukirento <yabukirento@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:20:00 by yabukirento       #+#    #+#             */
/*   Updated: 2025/04/18 15:20:59 by yabukirento      ###   ########.fr       */
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

// ボーナス: フラグと幅/精度の組み合わせテスト
void test_bonus_flags_width_precision(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== ボーナス: フラグと幅/精度のテスト =====%s\n", BLUE, RESET);
    
    // 最小フィールド幅のテスト
    printf("\n%s----- 最小フィールド幅テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%5d] [%10s]\n", 42, "hello");
    std_len = printf("printf:    [%5d] [%10s]\n", 42, "hello");
    compare_length(ft_len, std_len, "最小フィールド幅");
    
    // 左揃えフラグ (-) テスト
    printf("\n%s----- 左揃えフラグテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%-5d] [%-10s]\n", 42, "hello");
    std_len = printf("printf:    [%-5d] [%-10s]\n", 42, "hello");
    compare_length(ft_len, std_len, "左揃えフラグ");
    
    // ゼロパディング (0) テスト
    printf("\n%s----- ゼロパディングテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%05d] [%010d]\n", 42, -42);
    std_len = printf("printf:    [%05d] [%010d]\n", 42, -42);
    compare_length(ft_len, std_len, "ゼロパディング");
    
    // 精度指定子 (.) テスト
    printf("\n%s----- 精度指定子テスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%.3d] [%.5s]\n", 42, "hello");
    std_len = printf("printf:    [%.3d] [%.5s]\n", 42, "hello");
    compare_length(ft_len, std_len, "精度指定子");
    
    // 幅と精度の組み合わせテスト
    printf("\n%s----- 幅と精度の組み合わせテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%8.3d] [%10.5s]\n", 42, "hello");
    std_len = printf("printf:    [%8.3d] [%10.5s]\n", 42, "hello");
    compare_length(ft_len, std_len, "幅と精度");
    
    // 複雑な組み合わせテスト
    printf("\n%s----- 複雑な組み合わせテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%-8.3d] [%08.5d] [%-10.7s]\n", 42, 42, "hello");
    std_len = printf("printf:    [%-8.3d] [%08.5d] [%-10.7s]\n", 42, 42, "hello");
    compare_length(ft_len, std_len, "複雑な組み合わせ");
}

// ボーナス: 特殊フラグ (# +) のテスト
void test_bonus_special_flags(void)
{
    int ft_len, std_len;
    
    printf("\n%s===== ボーナス: 特殊フラグ (# +) のテスト =====%s\n", BLUE, RESET);
    
    // # フラグテスト (16進数)
    printf("\n%s----- # フラグテスト (16進数) -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%#x] [%#X]\n", 42, 42);
    std_len = printf("printf:    [%#x] [%#X]\n", 42, 42);
    compare_length(ft_len, std_len, "# フラグ (16進数)");
    
    // # フラグテスト (0値)
    printf("\n%s----- # フラグテスト (0値) -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%#x] [%#X]\n", 0, 0);
    std_len = printf("printf:    [%#x] [%#X]\n", 0, 0);
    compare_length(ft_len, std_len, "# フラグ (0値)");
    
    // + フラグテスト
    printf("\n%s----- + フラグテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+d] [%+i]\n", 42, -42);
    std_len = printf("printf:    [%+d] [%+i]\n", 42, -42);
    compare_length(ft_len, std_len, "+ フラグ");
    
    // スペースフラグテスト
    printf("\n%s----- スペースフラグテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [% d] [% i]\n", 42, -42);
    std_len = printf("printf:    [% d] [% i]\n", 42, -42);
    compare_length(ft_len, std_len, "スペースフラグ");
    
    // フラグの優先順位テスト (+ と スペース)
    printf("\n%s----- フラグ優先順位テスト (+ とスペース) -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+ d] [% +i]\n", 42, 42);
    std_len = printf("printf:    [%+ d] [% +i]\n", 42, 42);
    compare_length(ft_len, std_len, "+ とスペース");
    
    // 複合フラグテスト
    printf("\n%s----- 複合フラグテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+8d] [% 8d] [%#8x]\n", 42, 42, 42);
    std_len = printf("printf:    [%+8d] [% 8d] [%#8x]\n", 42, 42, 42);
    compare_length(ft_len, std_len, "複合フラグ");
    
    // すべてのフラグの組み合わせテスト
    printf("\n%s----- すべてのフラグ組み合わせテスト -----%s\n", YELLOW, RESET);
    ft_len = ft_printf("ft_printf: [%+-8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    std_len = printf("printf:    [%+-8.3d] [%+08.5d] [%#-8.3x]\n", 42, 42, 42);
    compare_length(ft_len, std_len, "すべてのフラグ");
}

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
    
    // ボーナステスト (ボーナス版でのみ成功します)
    printf("\n%s***** ボーナス機能テスト *****%s\n", BLUE, RESET);
    printf("%s注意: 以下のテストはボーナス版でのみ正常に動作します。%s\n", YELLOW, RESET);
    test_bonus_flags_width_precision();
    test_bonus_special_flags();
    
    print_summary();
    
    printf("\n%s***** テスト終了 *****%s\n\n", BLUE, RESET);
    return (0);
}