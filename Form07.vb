Public Class Form07
    Private Sub btn_go_Click(sender As Object, e As EventArgs) Handles btn_go.Click
        Dim start As Integer = CInt(tb_start.Text)
        Dim final As Integer = CInt(tb_final.Text)

        For i = start To final Step 1
            tb_result.AppendText("=========" & CStr(i) & "단=======" & vbCrLf)
            For j = 1 To 9 Step 1
                tb_result.AppendText(CStr(i) & " * " & CStr(j) & " = " & CStr(i * j) & vbCrLf)
            Next
            tb_result.AppendText(vbCrLf)
        Next

    End Sub
End Class