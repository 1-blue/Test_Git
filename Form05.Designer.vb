<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form05
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
        Me.lb_info = New System.Windows.Forms.Label()
        Me.btn_start = New System.Windows.Forms.Button()
        Me.tb_value = New System.Windows.Forms.TextBox()
        Me.SuspendLayout()
        '
        'lb_info
        '
        Me.lb_info.AutoSize = True
        Me.lb_info.Location = New System.Drawing.Point(24, 31)
        Me.lb_info.Name = "lb_info"
        Me.lb_info.Size = New System.Drawing.Size(79, 12)
        Me.lb_info.TabIndex = 0
        Me.lb_info.Text = "5의 배수의 합"
        '
        'btn_start
        '
        Me.btn_start.Location = New System.Drawing.Point(49, 79)
        Me.btn_start.Name = "btn_start"
        Me.btn_start.Size = New System.Drawing.Size(171, 32)
        Me.btn_start.TabIndex = 1
        Me.btn_start.Text = "5의 배수 구하기"
        Me.btn_start.UseVisualStyleBackColor = True
        '
        'tb_value
        '
        Me.tb_value.Location = New System.Drawing.Point(123, 28)
        Me.tb_value.Name = "tb_value"
        Me.tb_value.Size = New System.Drawing.Size(132, 21)
        Me.tb_value.TabIndex = 2
        '
        'Form05
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(285, 140)
        Me.Controls.Add(Me.tb_value)
        Me.Controls.Add(Me.btn_start)
        Me.Controls.Add(Me.lb_info)
        Me.Name = "Form05"
        Me.Text = "Form05"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents lb_info As Label
    Friend WithEvents btn_start As Button
    Friend WithEvents tb_value As TextBox
End Class
