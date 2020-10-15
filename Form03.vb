Public Class Form03
    Dim money As Integer
    Dim selection As Integer
    Dim orange As Integer
    Dim grape As Integer
    Dim apple As Integer
    Dim mango As Integer

    '프로그램실행시 기본설정
    Private Sub Form03_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        btn_buy.Enabled = False
        btn_return.Enabled = False
        selection = 0
        orange = 0
        grape = 0
        apple = 0
        mango = 0
        money = 0
        lb_return.Text = "잔액 : " & money & "원"
        tb_money.Select()
        AcceptButton = btn_go
    End Sub

    '투입버튼
    Private Sub btn_go_Click(sender As Object, e As EventArgs) Handles btn_go.Click
        If tb_money.Text = "" Then
            MsgBox("투입할 금액을 입력하세요.")
            tb_money.Select()
        Else
            money = CInt(tb_money.Text)
            tb_money.Enabled = False
            btn_buy.Enabled = True
            btn_return.Enabled = True
            btn_go.Enabled = False
            lb_return.Text = "잔액 : " & money & "원"
        End If
    End Sub

    '오렌지 1 // 포도 2 // 사과 3 // 망고 4
    Private Sub rb_orange_CheckedChanged(sender As Object, e As EventArgs) Handles rb_orange.CheckedChanged
        selection = 1
    End Sub

    Private Sub rb_grape_CheckedChanged(sender As Object, e As EventArgs) Handles rb_grape.CheckedChanged
        selection = 2
    End Sub

    Private Sub rb_apple_CheckedChanged(sender As Object, e As EventArgs) Handles rb_apple.CheckedChanged
        selection = 3
    End Sub

    Private Sub rb_mango_CheckedChanged(sender As Object, e As EventArgs) Handles rb_mango.CheckedChanged
        selection = 4
    End Sub


    '구매버튼
    Private Sub btn_buy_Click(sender As Object, e As EventArgs) Handles btn_buy.Click
        Select Case selection
            Case 1
                If money >= 1000 Then
                    money -= 1000
                    orange += 1
                Else
                    MsgBox("금액이 부족합니다.")
                End If
            Case 2
                If money >= 700 Then
                    money -= 700
                    grape += 1
                Else
                    MsgBox("금액이 부족합니다.")
                End If
            Case 3
                If money >= 500 Then
                    money -= 500
                    apple += 1
                Else
                    MsgBox("금액이 부족합니다.")
                End If
            Case 4
                If money >= 100 Then
                    money -= 100
                    mango += 1
                Else
                    MsgBox("금액이 부족합니다.")
                End If
        End Select

        lb_return.Text = "잔액 : " & money & "원"

        lb_state.Text = "오렌지주스 : " & orange & "개" & vbCrLf & "포도주스 : " & grape & "개" & vbCrLf & "사과주스 : " & apple & "개" & vbCrLf & "망고주스 : " & mango & "개"
    End Sub

    '잔액반환
    Private Sub btn_return_Click(sender As Object, e As EventArgs) Handles btn_return.Click
        btn_buy.Enabled = False
        btn_return.Enabled = False
        selection = 0
        orange = 0
        grape = 0
        apple = 0
        mango = 0
        money = 0

        lb_state.Text = ""
        tb_money.Text = CStr(money)
        tb_money.Enabled = True
        btn_buy.Enabled = False
        btn_return.Enabled = False
        btn_go.Enabled = True
        lb_return.Text = "잔액 : " & money & "원"
        tb_money.SelectAll()
    End Sub
End Class