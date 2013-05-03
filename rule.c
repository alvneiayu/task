static int nft_rule_snprintf_json(char *buf, size_t size, struct nft_rule *r,
				 uint32_t type, uint32_t flags)
{
	int ret, len = size, offset = 0;
	struct nft_rule_expr *expr;

	ret = snprintf(buf, size,
		"{ \"rule\": { \"family\" : %u, \"table\" : \"%s\", "
			"\"chain\"  : \"%s\", \"handle\" : %llu,",
				r->family, r->table, r->chain,
				(unsigned long long)r->handle);
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	ret = snprintf(buf+offset, len, "\"rule_flags\" : %u,"
					"\"compat_flags\" : %u,"
					"\"compat_proto\" : %u,",
					r->rule_flags,
					r->compat.flags, r->compat.proto);
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	list_for_each_entry(expr, &r->expr_list, head) {
		ret = snprintf(buf+offset, len,
				"\"expr\" : { \"type\" : \"%s\", \"value\" : \"", expr->ops->name);
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

		ret = expr->ops->snprintf(buf+offset, len, type, flags, expr);
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

		ret = snprintf(buf+offset, len, "\"}");
		SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	}
	ret = snprintf(buf+offset, len, "}}");
	SNPRINTF_BUFFER_SIZE(ret, size, len, offset);

	return ret;
}
