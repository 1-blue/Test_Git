<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class array1
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
        Me.btn_click = New System.Windows.Forms.Button()
        Me.lb_str = New System.Windows.Forms.Label()
        Me.tb_input = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'btn_click
        '
        Me.btn_click.Location = New System.Drawing.Point(141, 10)
        Me.btn_click.Name = "btn_click"
        Me.btn_click.Size = New System.Drawing.Size(75, 23)
        Me.btn_click.TabIndex = 0
        Me.btn_click.Text = "숫자입력"
        Me.btn_click.UseVisualStyleBackColor = True
        '
        'lb_str
        '
        Me.lb_str.AutoSize = True
        Me.lb_str.Location = New System.Drawing.Point(92, 76)
        Me.lb_str.Name = "lb_str"
        Me.lb_str.Size = New System.Drawing.Size(0, 12)
        Me.lb_str.TabIndex = 1
        '
        'tb_input
        '
        Me.tb_input.Location = New System.Drawing.Point(12, 12)
        Me.tb_input.Name = "tb_input"
        Me.tb_input.Size = New System.Drawing.Size(100, 21)
        Me.tb_input.TabIndex = 2
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(238, 118)
        Me.Controls.Add(Me.tb_input)
        Me.Controls.Add(Me.lb_str)
        Me.Controls.Add(Me.btn_click)
        Me.Name = "Form1"
        Me.Text = "Form1"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents btn_click As Button
    Friend WithEvents lb_str As Label
    Friend WithEvents tb_input As TextBox
End Class
