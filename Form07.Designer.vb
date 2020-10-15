<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form07
    Inherits System.Windows.Forms.Form

    'Form은 Dispose를 재정의하여 구성 요소 목록을 정리합니다.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows Form 디자이너에 필요합니다.
    Private components As System.ComponentModel.IContainer

    '참고: 다음 프로시저는 Windows Form 디자이너에 필요합니다.
    '수정하려면 Windows Form 디자이너를 사용하십시오.  
    '코드 편집기에서는 수정하지 마세요.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.lb_start = New System.Windows.Forms.Label()
        Me.tb_start = New System.Windows.Forms.TextBox()
        Me.btn_go = New System.Windows.Forms.Button()
        Me.lb_final = New System.Windows.Forms.Label()
        Me.tb_final = New System.Windows.Forms.TextBox()
        Me.tb_result = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'lb_start
        '
        Me.lb_start.AutoSize = True
        Me.lb_start.Location = New System.Drawing.Point(34, 41)
        Me.lb_start.Name = "lb_start"
        Me.lb_start.Size = New System.Drawing.Size(41, 12)
        Me.lb_start.TabIndex = 0
        Me.lb_start.Text = "시작단"
        '
        'tb_start
        '
        Me.tb_start.Location = New System.Drawing.Point(111, 32)
        Me.tb_start.Name = "tb_start"
        Me.tb_start.Size = New System.Drawing.Size(100, 21)
        Me.tb_start.TabIndex = 1
        '
        'btn_go
        '
        Me.btn_go.Location = New System.Drawing.Point(248, 30)
        Me.btn_go.Name = "btn_go"
        Me.btn_go.Size = New System.Drawing.Size(75, 23)
        Me.btn_go.TabIndex = 2
        Me.btn_go.Text = "Button1"
        Me.btn_go.UseVisualStyleBackColor = True
        '
        'lb_final
        '
        Me.lb_final.AutoSize = True
        Me.lb_final.Location = New System.Drawing.Point(34, 87)
        Me.lb_final.Name = "lb_final"
        Me.lb_final.Size = New System.Drawing.Size(41, 12)
        Me.lb_final.TabIndex = 0
        Me.lb_final.Text = "종료단"
        '
        'tb_final
        '
        Me.tb_final.Location = New System.Drawing.Point(111, 78)
        Me.tb_final.Name = "tb_final"
        Me.tb_final.Size = New System.Drawing.Size(100, 21)
        Me.tb_final.TabIndex = 1
        '
        'tb_result
        '
        Me.tb_result.Location = New System.Drawing.Point(36, 151)
        Me.tb_result.Multiline = True
        Me.tb_result.Name = "tb_result"
        Me.tb_result.ReadOnly = True
        Me.tb_result.ScrollBars = System.Windows.Forms.ScrollBars.Vertical
        Me.tb_result.Size = New System.Drawing.Size(319, 113)
        Me.tb_result.TabIndex = 1
        '
        'Form07
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(381, 294)
        Me.Controls.Add(Me.btn_go)
        Me.Controls.Add(Me.tb_final)
        Me.Controls.Add(Me.tb_result)
        Me.Controls.Add(Me.tb_start)
        Me.Controls.Add(Me.lb_final)
        Me.Controls.Add(Me.lb_start)
        Me.Name = "Form07"
        Me.Text = "Form07"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents lb_start As Label
    Friend WithEvents tb_start As TextBox
    Friend WithEvents btn_go As Button
    Friend WithEvents lb_final As Label
    Friend WithEvents tb_final As TextBox
    Friend WithEvents tb_result As TextBox
End Class
