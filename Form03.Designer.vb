<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form03
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
        Me.btn_buy = New System.Windows.Forms.Button()
        Me.lb_money = New System.Windows.Forms.Label()
        Me.tb_money = New System.Windows.Forms.TextBox()
        Me.rb_orange = New System.Windows.Forms.RadioButton()
        Me.rb_grape = New System.Windows.Forms.RadioButton()
        Me.rb_apple = New System.Windows.Forms.RadioButton()
        Me.rb_mango = New System.Windows.Forms.RadioButton()
        Me.lb_state = New System.Windows.Forms.Label()
        Me.lb_return = New System.Windows.Forms.Label()
        Me.btn_go = New System.Windows.Forms.Button()
        Me.btn_return = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'btn_buy
        '
        Me.btn_buy.Location = New System.Drawing.Point(35, 236)
        Me.btn_buy.Name = "btn_buy"
        Me.btn_buy.Size = New System.Drawing.Size(75, 23)
        Me.btn_buy.TabIndex = 0
        Me.btn_buy.Text = "구매"
        Me.btn_buy.UseVisualStyleBackColor = True
        '
        'lb_money
        '
        Me.lb_money.AutoSize = True
        Me.lb_money.Location = New System.Drawing.Point(33, 43)
        Me.lb_money.Name = "lb_money"
        Me.lb_money.Size = New System.Drawing.Size(29, 12)
        Me.lb_money.TabIndex = 1
        Me.lb_money.Text = "금액"
        '
        'tb_money
        '
        Me.tb_money.Location = New System.Drawing.Point(120, 40)
        Me.tb_money.Name = "tb_money"
        Me.tb_money.Size = New System.Drawing.Size(129, 21)
        Me.tb_money.TabIndex = 2
        '
        'rb_orange
        '
        Me.rb_orange.AutoSize = True
        Me.rb_orange.Location = New System.Drawing.Point(35, 101)
        Me.rb_orange.Name = "rb_orange"
        Me.rb_orange.Size = New System.Drawing.Size(131, 16)
        Me.rb_orange.TabIndex = 3
        Me.rb_orange.TabStop = True
        Me.rb_orange.Text = "오렌지주스 : 1000원"
        Me.rb_orange.UseVisualStyleBackColor = True
        '
        'rb_grape
        '
        Me.rb_grape.AutoSize = True
        Me.rb_grape.Location = New System.Drawing.Point(35, 132)
        Me.rb_grape.Name = "rb_grape"
        Me.rb_grape.Size = New System.Drawing.Size(113, 16)
        Me.rb_grape.TabIndex = 3
        Me.rb_grape.TabStop = True
        Me.rb_grape.Text = "포도주스 : 700원"
        Me.rb_grape.UseVisualStyleBackColor = True
        '
        'rb_apple
        '
        Me.rb_apple.AutoSize = True
        Me.rb_apple.Location = New System.Drawing.Point(35, 163)
        Me.rb_apple.Name = "rb_apple"
        Me.rb_apple.Size = New System.Drawing.Size(113, 16)
        Me.rb_apple.TabIndex = 3
        Me.rb_apple.TabStop = True
        Me.rb_apple.Text = "사과주스 : 500원"
        Me.rb_apple.UseVisualStyleBackColor = True
        '
        'rb_mango
        '
        Me.rb_mango.AutoSize = True
        Me.rb_mango.Location = New System.Drawing.Point(35, 195)
        Me.rb_mango.Name = "rb_mango"
        Me.rb_mango.Size = New System.Drawing.Size(113, 16)
        Me.rb_mango.TabIndex = 3
        Me.rb_mango.TabStop = True
        Me.rb_mango.Text = "망고주스 : 100원"
        Me.rb_mango.UseVisualStyleBackColor = True
        '
        'lb_state
        '
        Me.lb_state.AutoSize = True
        Me.lb_state.Location = New System.Drawing.Point(192, 101)
        Me.lb_state.Name = "lb_state"
        Me.lb_state.Size = New System.Drawing.Size(0, 12)
        Me.lb_state.TabIndex = 1
        '
        'lb_return
        '
        Me.lb_return.AutoSize = True
        Me.lb_return.Location = New System.Drawing.Point(152, 243)
        Me.lb_return.Name = "lb_return"
        Me.lb_return.Size = New System.Drawing.Size(0, 12)
        Me.lb_return.TabIndex = 1
        '
        'btn_go
        '
        Me.btn_go.Location = New System.Drawing.Point(287, 38)
        Me.btn_go.Name = "btn_go"
        Me.btn_go.Size = New System.Drawing.Size(75, 23)
        Me.btn_go.TabIndex = 0
        Me.btn_go.Text = "투입"
        Me.btn_go.UseVisualStyleBackColor = True
        '
        'btn_return
        '
        Me.btn_return.Location = New System.Drawing.Point(287, 236)
        Me.btn_return.Name = "btn_return"
        Me.btn_return.Size = New System.Drawing.Size(75, 23)
        Me.btn_return.TabIndex = 0
        Me.btn_return.Text = "잔액반환"
        Me.btn_return.UseVisualStyleBackColor = True
        '
        'Form03
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(404, 293)
        Me.Controls.Add(Me.rb_mango)
        Me.Controls.Add(Me.rb_apple)
        Me.Controls.Add(Me.rb_grape)
        Me.Controls.Add(Me.rb_orange)
        Me.Controls.Add(Me.tb_money)
        Me.Controls.Add(Me.lb_return)
        Me.Controls.Add(Me.lb_state)
        Me.Controls.Add(Me.btn_return)
        Me.Controls.Add(Me.btn_go)
        Me.Controls.Add(Me.lb_money)
        Me.Controls.Add(Me.btn_buy)
        Me.Name = "Form03"
        Me.Text = "음료자판기"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents btn_buy As Button
    Friend WithEvents lb_money As Label
    Friend WithEvents tb_money As TextBox
    Friend WithEvents rb_orange As RadioButton
    Friend WithEvents rb_grape As RadioButton
    Friend WithEvents rb_apple As RadioButton
    Friend WithEvents rb_mango As RadioButton
    Friend WithEvents lb_state As Label
    Friend WithEvents lb_return As Label
    Friend WithEvents btn_go As Button
    Friend WithEvents btn_return As Button
End Class
