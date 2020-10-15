<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form06
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
        Me.tb_start = New System.Windows.Forms.TextBox()
        Me.tb_end = New System.Windows.Forms.TextBox()
        Me.tb_increase = New System.Windows.Forms.TextBox()
        Me.tb_result = New System.Windows.Forms.TextBox()
        Me.btn_culculate = New System.Windows.Forms.Button()
        Me.lb_start = New System.Windows.Forms.Label()
        Me.lb_end = New System.Windows.Forms.Label()
        Me.lb_lable = New System.Windows.Forms.Label()
        Me.lb_result = New System.Windows.Forms.Label()
        Me.SuspendLayout()
        '
        'tb_start
        '
        Me.tb_start.Location = New System.Drawing.Point(52, 37)
        Me.tb_start.Name = "tb_start"
        Me.tb_start.Size = New System.Drawing.Size(100, 21)
        Me.tb_start.TabIndex = 0
        '
        'tb_end
        '
        Me.tb_end.Location = New System.Drawing.Point(213, 37)
        Me.tb_end.Name = "tb_end"
        Me.tb_end.Size = New System.Drawing.Size(100, 21)
        Me.tb_end.TabIndex = 0
        '
        'tb_increase
        '
        Me.tb_increase.Location = New System.Drawing.Point(376, 37)
        Me.tb_increase.Name = "tb_increase"
        Me.tb_increase.Size = New System.Drawing.Size(100, 21)
        Me.tb_increase.TabIndex = 0
        '
        'tb_result
        '
        Me.tb_result.Location = New System.Drawing.Point(114, 144)
        Me.tb_result.Name = "tb_result"
        Me.tb_result.Size = New System.Drawing.Size(100, 21)
        Me.tb_result.TabIndex = 0
        '
        'btn_culculate
        '
        Me.btn_culculate.Location = New System.Drawing.Point(295, 134)
        Me.btn_culculate.Name = "btn_culculate"
        Me.btn_culculate.Size = New System.Drawing.Size(127, 50)
        Me.btn_culculate.TabIndex = 1
        Me.btn_culculate.Text = "계산"
        Me.btn_culculate.UseVisualStyleBackColor = True
        '
        'lb_start
        '
        Me.lb_start.AutoSize = True
        Me.lb_start.Location = New System.Drawing.Point(4, 40)
        Me.lb_start.Name = "lb_start"
        Me.lb_start.Size = New System.Drawing.Size(41, 12)
        Me.lb_start.TabIndex = 2
        Me.lb_start.Text = "시작값"
        '
        'lb_end
        '
        Me.lb_end.AutoSize = True
        Me.lb_end.Location = New System.Drawing.Point(165, 40)
        Me.lb_end.Name = "lb_end"
        Me.lb_end.Size = New System.Drawing.Size(29, 12)
        Me.lb_end.TabIndex = 2
        Me.lb_end.Text = "끝값"
        '
        'lb_lable
        '
        Me.lb_lable.AutoSize = True
        Me.lb_lable.Location = New System.Drawing.Point(328, 40)
        Me.lb_lable.Name = "lb_lable"
        Me.lb_lable.Size = New System.Drawing.Size(41, 12)
        Me.lb_lable.TabIndex = 2
        Me.lb_lable.Text = "증가값"
        '
        'lb_result
        '
        Me.lb_result.AutoSize = True
        Me.lb_result.Location = New System.Drawing.Point(50, 147)
        Me.lb_result.Name = "lb_result"
        Me.lb_result.Size = New System.Drawing.Size(29, 12)
        Me.lb_result.TabIndex = 2
        Me.lb_result.Text = "합계"
        '
        'Form06
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(492, 212)
        Me.Controls.Add(Me.lb_result)
        Me.Controls.Add(Me.lb_lable)
        Me.Controls.Add(Me.lb_end)
        Me.Controls.Add(Me.lb_start)
        Me.Controls.Add(Me.btn_culculate)
        Me.Controls.Add(Me.tb_increase)
        Me.Controls.Add(Me.tb_result)
        Me.Controls.Add(Me.tb_end)
        Me.Controls.Add(Me.tb_start)
        Me.Name = "Form06"
        Me.Text = "Form06"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents tb_start As TextBox
    Friend WithEvents tb_end As TextBox
    Friend WithEvents tb_increase As TextBox
    Friend WithEvents tb_result As TextBox
    Friend WithEvents btn_culculate As Button
    Friend WithEvents lb_start As Label
    Friend WithEvents lb_end As Label
    Friend WithEvents lb_lable As Label
    Friend WithEvents lb_result As Label
End Class
